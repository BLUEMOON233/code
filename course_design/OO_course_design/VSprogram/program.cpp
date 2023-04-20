#include <iostream>
#include "StudentManager.h"
using namespace std;

int main() {
	StudentManager sm;
	StudentSegment sg;
	sg.build(sm, sg.getRoot(), 1, sm.getCount());
}