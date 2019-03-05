/*=========================================================================
 *
 *  Copyright (c) 2019 Sunnybrook Research Institute
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#ifndef SEDEEN_SRC_PLUGINS_TESTPLUGIN_TESTPLUGIN_H
#define SEDEEN_SRC_PLUGINS_TESTPLUGIN_TESTPLUGIN_H

//Sedeen required headers
#include "algorithm/AlgorithmBase.h"
#include "algorithm/Parameters.h"
#include "algorithm/Results.h"
//

namespace sedeen {   
namespace algorithm {

class testPlugin : public AlgorithmBase {
public:
	// Constructor
	testPlugin();
	// Destructor
	virtual ~testPlugin();

	// Other public methods you would like to include

private:
	//Private methods
	virtual void run();
	virtual void init(const image::ImageHandle& image);

private:
	//Private variables
	DisplayAreaParameter _display_area;
	ImageResult _result;

};

} // namespace algorithm
} // namespace sedeen

#endif