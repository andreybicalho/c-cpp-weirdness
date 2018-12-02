#pragma once

// here is an example of a a bunch of include we need in our project and must be included.
// if we include this in another translation unit it will compile this whole thing every single time, and thus will take a long time.

// how to make it pre-compiled:
// right click on the pch.cpp file (yes, the .cpp one), properties
// under C/C++ go to Precompiled Header and make it Create (/Yc)
// precompiled header file can be left empty

// then

// right click on the entire project (not solution), properties
// under C/C++ go to Precompiled Header and make it Use (/Yu)
// in precompiled header file we select the pch.h file
// now this will be applied to every single translation unit file (.cpp) in our project, but our pch.cpp of course 
// for instance, right click on the main.cpp file and check its properties, it will use our pch.h precompiled file


#include <iostream>
#include <algorithm>
#include <functional>
#include <thread>
#include <memory>
#include <utility>

#include <string>
#include <stack>
#include <deque>
#include <array>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <Windows.h>