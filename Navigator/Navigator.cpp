// Navigator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
void out_put(int start, int end, int cur){
	int i = start;
	for (; i <= end; i++){
		if (i == cur) printf("* ");
		else printf("%d ", i);
	}
}
void navi(int cur, int page){
	int show = 9, hf = show / 2;
	if (cur != 1) printf("Prev ");
	if (page <= show){
		out_put(1, page, cur);
	}
	else {
		if (cur - 1 < hf + 2){
			out_put(1, cur, cur);
		}
		else {
			printf("1 ");
			if (page != show + 1) printf("... ");
			out_put(cur - hf + (page - cur - hf > 0 ? 0 : page - cur - hf), cur, cur);
		}
		if (page - cur < hf + 2){
			out_put(cur + 1, page, cur);
		}
		else {
			out_put(cur + 1, cur + hf - (cur - hf > 1 ? 0 : cur - hf - 1), cur);
			if (page != show + 1) printf("... ");
			printf("%d ", page);
		}
	}
	if (cur != page) printf("Next");
}
int main(int argc, char** argv){
	if (argc != 3){
		printf("Parameters error!\n");
		return -1;
	}
	navi(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return 0;
}
