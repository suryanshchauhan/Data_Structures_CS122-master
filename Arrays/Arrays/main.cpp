/////////////////////////////////////////////////////////////////////////
// Steven Bogaerts
/////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main() {
	int nums[4] = {2,5,7,8};

	for(int i = 0; i < 4; i++)
		cout << "Index: " << i 
		     << ", value: " << nums[i] 
	         << ", address: " << &(nums[i]) 
		     << endl;

	return 0;
}