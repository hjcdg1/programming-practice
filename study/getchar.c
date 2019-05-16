#include <stdio.h>

int main(void)
{
	int c;

	while((c=getchar())!=EOF)	//	엔터키를 누르면 여태까지 입력한 문자들이 모두 입력버퍼에 들어감(개행문자까지)
	{				//	그리고 이제 getchar()가 입력버퍼에 존재하는 문자들을 하나씩 차례로 읽는 것이다.
		putchar(c);
		putchar(c);
	}				//	참고로 내가 막 만든 data.in과 같은 파일의 끝에는 자동으로 개행 문자가 삽입되더라. (vim의 특징..?)
	return 0;
}
