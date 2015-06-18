#include <stdio.h>
 
int main(void) {
    int a;
    int b;
    int c;
    scanf("%d%d%d",&a,&b,&c);
    //a,b,cの並べ方は全部で3!=6通りなので、それを全部試せばよい
    if(a<=b&&b<=c) printf("%d %d %d\n",a,b,c);
    else if(a<=c&&c<=b) printf("%d %d %d\n",a,c,b);
    else if(b<=a&&a<=c) printf("%d %d %d\n",b,a,c);
    else if(b<=c&&c<=a) printf("%d %d %d\n",b,c,a);
    else if(c<=a&&a<=b) printf("%d %d %d\n",c,a,b);
    else if(c<=b&&b<=a) printf("%d %d %d\n",c,b,a);
    /*
    // 別解
    // 入力を配列で受け取って、配列をソートすればよい。
    // このコードではバブルソートでソートしている。
    int a[3];
    int i,j;
    int t;
    for(i=0;i<3;i++){
    	scanf("%d",&a[i]);
    }
    // jのループを回すたびに配列の右側から降順で要素が確定していく。
    for(i=0;i<3;i++){
    	for(j=0;j+1<3-i;j++){
    		if(a[j]>a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;			
    		}
    	}
    }
    printf("%d %d %d\n",a[0],a[1],a[2]);
    // もう１つの別解
    // ３つの数字の最大値と最小値と合計を求める。
    // 求める答えを a1 a2 a3 とすると、
    // a1=最小値
    // a2=合計-最大値-最小値
    // a3=最大値
    // となる。
    // 最小値や最大値を求める場合はif文を使って求めてもいいが、
    // math.hをincludeすればfmin(),fmax()という関数が使える。
    
    // #include <stdio.h>
	// #include <math.h> <- これを付け加える

    int a,b,c;
    int MIN=1000,MAX=-1000,SUM=0;
    scanf("%d %d %d",&a,&b,&c);
	MIN=fmin(MIN,a);
	MIN=fmin(MIN,b);
	MIN=fmin(MIN,c);
	MAX=fmax(MAX,a);
	MAX=fmax(MAX,b);
	MAX=fmax(MAX,c);
	SUM=a+b+c;
	printf("%d %d %d\n",MIN,SUM-MAX-MIN,MAX);
	*/
    return 0;
}