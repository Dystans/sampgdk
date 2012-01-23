// Copyright (c) 2011 Zeex
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//	 http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <sampgdk/config.h>
#include <sampgdk/amx/amx.h>

#include "natives.h"

NativeManager::NativeManager() 
	: natives_()
{
}

NativeManager &NativeManager::GetInstance() {
	static NativeManager inst;
	return inst;
}

AMX_NATIVE NativeManager::GetNative(const char *name) const {
	std::map<std::string, AMX_NATIVE>::const_iterator iter = 
		natives_.find(name);
	if (iter == natives_.end()) {
		return 0;
	}
	return iter->second;
}

void NativeManager::SetNative(const char *name, AMX_NATIVE native) {
	natives_[std::string(name)] = native;
}
