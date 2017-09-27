#include <iostream>
#include <cstdio>

class UnionFind
{
private:
// data 
int id[];
int size[];
// methods

public:
// Constructor
UnionFind(int n){
	//This takes O(n) time to initialize
	id[n];
	for (int i = 0; i < n; i++){
		id[i] = i;
	}
}

// Destructor
~UnionFind(){
printf("Deconstructing...\n");
}


// Find operation
int Find(int x){
	//The first line makes every other node in the path point to its grandparent. Effectively reducing operation time by 1/2. Some call this path compression...
	while (x != id[x]) {
		id[x] = id[id[x]];
		x = id[x];
	      }

return x;
}

//Connected operation
bool Connected(int x, int y){
//If the x and y end up at the same root, then they are connected.
if(Find(x) == Find(y))
printf("T\n\n");
//Otherwise, they cannot be connected.
else
printf("F\n\n");
}

// Union operation
void Union(int x, int y){
	int i = Find(x);
	int j = Find(y);

	//If the tree containing x is larger than the tree containing y, merge the y tree into the x tree.
	if (size[i] < size[j]) {
	id[i] = j;
	size[j] += size[i];
	}
	//If it is the other way around, merge the x tree into the y tree.
	else{
	id[j] = i;
	size[i] += size[j];
	std::cout << size;
	}
}

};


int main(void){
	

	//n is the number of computers/components
	int n;
	//op is the operation (either 0 or 1), x and y are the 
	int op, x, y;
	
	printf("How many computers are going to be connected?\n");
	scanf("%d", &n);
	printf("Please input the operation type and its arguments.\n");
	UnionFind *uf = new UnionFind(n);
	 while (3 == scanf("%d %d %d", &op, &x, &y))
		 {
		 printf("%d %d %d\n", op, x, y);
		 if (op == -1 && x == -1 && y == -1) break;
		 if (!op) /* Connect/ Union*/ {
		printf("Calling for a union of %d and %d...\n",x,y);
	 		uf->Union(x,y);
	 	}
 		else /* Connected/ Find*/ {
		printf("Checking to see if %d and %d are connected...\n",x,y);
 			uf->Find(x);
			uf->Find(y);
			uf->Connected(x,y);
 		}
 	}
 uf->~UnionFind();
 return 0;
}
