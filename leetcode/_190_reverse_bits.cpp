//==============================================================================
// Copyright 2016 Windy Darian (Ruoyu Fan)
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//==============================================================================

// https://leetcode.com/problems/reverse-bits/


class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		n = (n & 0xFFFF0000) >> 16 | (n & 0x0000FFFF) << 16;
		n = (n & 0xFF00FF00) >> 8 | (n & 0x00FF00FF) << 8;
		n = (n & 0xF0F0F0F0) >> 4 | (n & 0x0F0F0F0F) << 4;
		n = (n & 0xCCCCCCCC) >> 2 | (n & 0x33333333) << 2;
		n = (n & 0xAAAAAAAA) >> 1 | (n & 0x55555555) << 1;
		return n;
	}
};
