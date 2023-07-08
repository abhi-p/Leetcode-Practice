/*
207. Course Schedule
Medium
12.2K
478
Companies

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

 

Constraints:

    1 <= numCourses <= 2000
    0 <= prerequisites.length <= 5000
    prerequisites[i].length == 2
    0 <= ai, bi < numCourses
    All the pairs prerequisites[i] are unique.
*/

#include <vector>
#include <unordered_set>
#include <iostream>
#include <map>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	bool ret = false;
	int numCoursesWithoutPrereqs = 0, coursesTaken = 0;
	
	//Number of prereqs of each course
	vector<int> courses (numCourses, 0);

	//Which courses have a dependancy on each course
		//To take courses dependancyMap[c], we have to take course c
		//Use this to decrement number of prereqs of dependant courses 
	map<int, vector<int>> dependancyMap;

	//Courses with no prereqs
	unordered_set<int> noPrereqsCourses;

	//Assume all courses have no prereqs
	for(int i = 0; i < courses.size(); i++){
		noPrereqsCourses.insert(i);
	}

	for(auto prereq : prerequisites){
		courses[prereq[0]] += 1;

		//To take prereq[0], we must take prereq[1]
		//Therefore prereq[0] has a dependancy on prereq[1] 
		dependancyMap[prereq[1]].push_back(prereq[0]);

		//prereq[0] has atleast one prereq, remove it from set of courses with no prereqs
		noPrereqsCourses.erase(prereq[0]);
	}

	numCoursesWithoutPrereqs = noPrereqsCourses.size();
	
	/*cout<<"Courses without prereqs: "<<numCoursesWithoutPrereqs<<endl;	
	for(auto c : noPrereqsCourses){
		cout<<c<<endl;
	}

	cout<<"Dependancy map"<<endl;
	for(auto keyValPair : dependancyMap){
		cout<<"Course: "<<keyValPair.first<<" depends on: "<<endl;

		for(auto dep : keyValPair.second){
			cout<<dep<<endl;
		}
	}	
	cout<<endl;
	*/

	//Return false if there are no courses without prereqs - indicative of a dependancy cycle
	if(numCoursesWithoutPrereqs == 0)
		ret = false;
	else{
		while(coursesTaken < numCourses){
			//find a course without prereq - take it - reduce number of prereqs required by dependant courses by 1
			//Check that there are courses with no prereqs to take
			if(noPrereqsCourses.size() == 0){
				//break out of infinite loop if there are no courses we can take			
				break;
			}
			unordered_set<int> newNoPrereqCourses;
			unordered_set<int> takenCourses;

			//cout<<"Iterating over noPrereqsCourses"<<endl;
			for(auto noPC : noPrereqsCourses){
				coursesTaken += 1;

				cout<<"Taking course: "<< noPC <<" coursesTaken: "<<coursesTaken<<endl;
				takenCourses.insert(noPC);
				//Reduce number of prereqs for dependancy courses
				if(dependancyMap.count(noPC) != 0){

					for(auto c : dependancyMap[noPC]){
						cout<<"Dependant course: "<< c <<endl;
						courses[c] -= 1;
						if(courses[c] == 0)
							newNoPrereqCourses.insert(c);//noPrereqsCourses.insert(c);
					}
				}
				//Mark course as taken
				courses[noPC] = -1;
				//noPrereqsCourses.erase(noPC);
			}
			for(auto newC : newNoPrereqCourses)	
				noPrereqsCourses.insert(newC);
			for(auto takenC : takenCourses)	
				noPrereqsCourses.erase(takenC);
		}	
	}

	//Check to see if number of courses taken == number of courses
	if(coursesTaken == numCourses)
		ret = true;
	return ret;
}

int main(){
	int numCourses;
	vector<vector<int>> prereqs;

	cout<<boolalpha;
	numCourses = 2;
	prereqs = {{1, 0}};
	cout<<canFinish(numCourses, prereqs)<<endl;

	numCourses = 2;
	prereqs = {{1, 0}, {0, 1}};
	cout<<canFinish(numCourses, prereqs)<<endl;

	numCourses = 2;
	prereqs = {{0, 1}};
	cout<<canFinish(numCourses, prereqs)<<endl;
	
	numCourses = 20;
	prereqs = {{0, 10}, {3, 18}, {5, 5}, {6, 11}, {11, 14}, {13, 1}, {15, 1}, {17, 4}};
	cout<<canFinish(numCourses, prereqs)<<endl;

}
/*
Python implementation

from collections import defaultdict

def canFinish(numCourses, prerequisites):
  takenCourses = 0
  adjList = defaultdict(list)
  inDegree= defaultdict(int)
  
  noDep=set(range(numCourses))
  #print(noDep)
  
  for pair in prerequisites:
    adjList[pair[0]].append(pair[1])
    inDegree[pair[1]]+=1
    noDep.discard(pair[1])

  for i in range(numCourses):
    if i not in adjList:
      adjList[i]=[]

    '''if i not in inDegree:
      inDegree[i]=0
    '''
  takenCourses += len(noDep)
  if len(noDep)==0 and takenCourses<numCourses:
    return False
  
  while noDep:
    course=noDep.pop()
    for depC in adjList[course]:
      inDegree[depC] -= 1
      if(inDegree[depC] == 0):
        takenCourses += 1
        noDep.add(depC)
        inDegree.pop(depC)
  print(takenCourses,numCourses)
  return takenCourses == numCourses
*/
