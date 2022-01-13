#include <cstdio>

#define check (r + g < b - 1 || g + b < r - 1 || b + r < g - 1)
using namespace std;
void Sol(){
	int r, g, b;
	scanf("%d%d%d", &r, &g, &b);
	puts(check ? "No" : "Yes");
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--)
	    Sol();
	return 0;
}
