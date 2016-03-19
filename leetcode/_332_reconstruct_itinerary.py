#-*- coding:utf-8 -*-
# ==============================================================================
#   Copyright 2016 Windy Darian (Ruoyu Fan)
#
#   Licensed under the Apache License, Version 2.0 (the "License");
#   you may not use this file except in compliance with the License.
#   You may obtain a copy of the License at
#
#        http://www.apache.org/licenses/LICENSE-2.0
#
#    Unless required by applicable law or agreed to in writing, software
#    distributed under the License is distributed on an "AS IS" BASIS,
#    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#    See the License for the specific language governing permissions and
#    limitations under the License.
# ==============================================================================
'''
Created on March 19, 2016
https://leetcode.com/problems/reconstruct-itinerary/
@author: Windy Darian (Ruoyu Fan)
'''

# Note: I should have used Hierholzer's algorithm for the Eulerian path but...


from bisect import insort_left


class Solution(object):
    def add_tickets(self, tickets):
        # type: list[[str,str]] -> None
        """
        add tickets to the tickets to choose from.
        used in initialization and putting tickets back when find a wrong
        itinerary
        """
        for ticket in tickets:
            if ticket[0] not in self.ticket_dict:
                self.ticket_dict[ticket[0]] = [ticket]
            else:
                # always insert in order so the result is always of a smaller
                #  lexical order
                insort_left(self.ticket_dict[ticket[0]], ticket)

    def search_itinerary(self, from_key):
        # type: str -> list[[str, str]]
        """
        given a starting airport, recursively return a valid itinerary that uses
        up all tickets
        """
        tickets_from_key = self.ticket_dict.get(from_key)
        if not tickets_from_key:
            return []

        from_index = 0
        while True:
            current_ticket = tickets_from_key.pop(from_index)
            results = [current_ticket]
            results.extend(self.search_itinerary(current_ticket[1]))
            if not tickets_from_key:
                return results
            # else
            # if there are tickets left, it is not a valid itinerary, return
            #  all the tickets to the ticket_dict and begin another search
            self.add_tickets(results)
            from_index = from_index + 1


    def findItinerary(self, tickets):
        # LeetCode solution entry
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        self.ticket_dict = {}
        self.add_tickets(tickets)
        tickets_route = self.search_itinerary("JFK")

        if not tickets_route:
            return []

        result = [tickets_route[0][0]]
        for ticket in tickets_route:
            result.append(ticket[1])

        return result
