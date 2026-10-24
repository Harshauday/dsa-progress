#include <string>
#include <vector>
#include <algorithm>

class Solution {
private:
    // Helper function to convert "MM-DD" to a day number from 1 to 365
    int getDayOfYear(std::string date, const std::vector<int>& monthDays) {
        // Use std::stoi to correctly convert substrings to integers
        int month = std::stoi(date.substr(0, 2));
        int day = std::stoi(date.substr(3, 2));
        
        int totalDays = 0;
        // Sum up all days of the preceding months
        for (int i = 1; i < month; ++i) {
            totalDays += monthDays[i];
        }
        return totalDays + day;
    }

public:
    int countDaysTogether(std::string arriveAlice, std::string leaveAlice, 
                          std::string arriveBob, std::string leaveBob) {
        
        std::vector<int> monthDays = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        // Convert all dates to absolute days of the year
        int aliceStart = getDayOfYear(arriveAlice, monthDays);
        int aliceEnd = getDayOfYear(leaveAlice, monthDays);
        int bobStart = getDayOfYear(arriveBob, monthDays);
        int bobEnd = getDayOfYear(leaveBob, monthDays);
        
        // Find the intersection of the two date ranges
        int overlapStart = std::max(aliceStart, bobStart);
        int overlapEnd = std::min(aliceEnd, bobEnd);
        
        // If they overlap, return the difference + 1; otherwise, return 0
        if (overlapStart <= overlapEnd) {
            return overlapEnd - overlapStart + 1;
        }
        
        return 0;
    }
};
