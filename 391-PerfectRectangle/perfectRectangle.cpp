/*
391. Perfect Rectangle
Hard
767
112
Companies

Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle. The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).

Return true if all the rectangles together form an exact cover of a rectangular region.

 

Example 1:

Input: rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
Output: true
Explanation: All 5 rectangles together form an exact cover of a rectangular region.

Example 2:

Input: rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
Output: false
Explanation: Because there is a gap between the two rectangular regions.

Example 3:

Input: rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
Output: false
Explanation: Because two of the rectangles overlap with each other.

 

Constraints:

    1 <= rectangles.length <= 2 * 104
    rectangles[i].length == 4
    -105 <= xi, yi, ai, bi <= 105
*/

#include <vector>
#include <set>
#include <iostream>
#include <utility>

using namespace std;

void printSet(set<pair<int, int>> inputSet){
	for (auto corner : inputSet) {
		cout<<corner.first<<" " << corner.second<<endl;
	}
	cout<<endl;
}


bool isRectangleCover(vector<vector<int>>& rectangles) {
	bool retVal = false;
	pair<int, int> corner;

	set<pair<int, int>> cornerSet;

	for (auto rectangle : rectangles) {
		int x_i = rectangle[0], y_i = rectangle[1], a_i = rectangle[2], b_i = rectangle[3];
		cout<<"x_i: "<< x_i << " y_i: " << y_i << " a_i: " << a_i << " b_i: " << b_i<<endl;
		vector<pair<int,int>> corners;
		corners.push_back(make_pair(x_i, y_i));
		corners.push_back(make_pair(a_i, y_i));
		corners.push_back(make_pair(x_i, b_i));
		corners.push_back(make_pair(a_i, b_i));

		for (auto corner : corners) {
			if (cornerSet.count(corner) > 0) {
				cornerSet.erase(corner);
			}
			else {
				cornerSet.insert(corner);
			}
		}
		if (cornerSet.size() == 0)
			return false;
		/*
		pair<int, int> bottomLeft (x_i, y_i);
		pair<int, int> bottomRight (a_i, y_i);
		pair<int, int> topLeft (x_i, b_i);
		pair<int, int> topRight (a_i, b_i);	
		
		cornerSet.insert(bottomLeft);
		cornerSet.insert(bottomRight);
		cornerSet.insert(topLeft);
		cornerSet.insert(topRight);
		*/
	}
	printSet(cornerSet);
	if(cornerSet.size() == 4)
		retVal = true;
	return retVal;
}


int main(){

	vector<vector<int>> inputRectangles;
	cout<<boolalpha<<endl;
	//False - rectangles overlap
	inputRectangles = {{1,1,3,3},{3,1,4,2},{1,3,2,4},{2,2,4,4}};
	cout<<isRectangleCover(inputRectangles)<<endl;

	//False - gap between rectangles
	inputRectangles = {{1,1,2,3},{1,3,2,4},{3,1,4,2},{3,2,4,4}};
	cout<<isRectangleCover(inputRectangles)<<endl;

	//True
	inputRectangles = {{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
	cout<<isRectangleCover(inputRectangles)<<endl;

	//False
	inputRectangles = {{1,1,2,2},{1,1,2,2},{2,1,3,2}};
	cout<<isRectangleCover(inputRectangles)<<endl;


}
