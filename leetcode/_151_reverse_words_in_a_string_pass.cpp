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
//
// Created on Oct 22, 2016
// https://leetcode.com/problems/reverse-words-in-a-string/

// This passed the test cases

#include <string>
#include <algorithm>

class Solution
{
private:
	template <typename Iter>
	void swapSubString(Iter begin, Iter end)
	{
		end -= 1;
		while (begin < end)
		{
			std::swap(*begin, *end);
			begin++;
			end--;
		}
	}

	void removeSpareSpaces(std::string &s)
	{
		if (s.begin() == s.end()) { return; }

		auto pslow = s.begin();
		auto pfast = s.begin();
		auto end = s.end();
		while (true)
		{
			while (pfast < end && *pfast == ' ')
			{
				pfast++;
			}

			while (pfast < end && *pfast != ' ')
			{
				std::swap(*pfast, *pslow);
				pslow++;
				pfast++;
				if (pfast < end && *pfast == ' ')
				{
					// add space after word
					std::swap(*pfast, *pslow);
					pfast++;
					pslow++;
				}
			}

			if (pfast == end)
			{
				break;
			}
		}
		s.resize(pslow - s.begin());

		if (s.size() > 0 && s.back() == ' ')
		{
			s.resize(s.size() - 1);
		}
	}

public:
	void reverseWords(std::string &s)
	{
		removeSpareSpaces(s);

		// Step 1: reverse the whole string
		auto begin = s.begin();
		auto end = s.end();

		if (begin == end) { return; }

		swapSubString(begin, end);

		// Step 2: reverse each word
		auto p = begin;
		while (p < end)
		{
			while (*p == ' ')
			{
				p++;
			}
			if (p == end) {break;}
			auto wbegin = p;
			while (p < end && *p != ' ')
			{
				p++;
			}
			auto wend = p;
			swapSubString(wbegin, wend);
		}
	}
};
