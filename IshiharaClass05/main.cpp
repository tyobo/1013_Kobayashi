#include <stdio.h>

/*
オブジェクトの生成と破棄
C++ではメモリ確保をnew/deleteを使うことで行うことができる。
まずは、メモリ確保のやり方以前に、
なぜメモリ確保を必要とするのか話していきます。
*/

/*
なぜメモリ確保が必要なのか
ゲームに限らず、すべてのアプリケーションにおいて、
膨大なデータを扱うアプリケーションはそのすべてのデータを、
メモリ上に展開することはできない。
なぜなら、メモリが有限だからです。
メモリが無限であれば、メモリ確保を使う必要はありません。
しかし、現実的にメモリが無限ということはないので、
メモリ確保の機能を利用し、
メモリをそのタイミングに必要な量だけ使う、
ということができるので、
メモリ確保はメモリが無限になるまでは、
必要な技術になります。

メリット:
有限なメモリを、その時々に必要な量だけ使うことができる。

デメリット：
確保したメモリの解放を忘れると、メモリリークして、バグの原因になる。
そもそもメモリ確保の処理は重たい。
*/

/*
new
newの処理はメモリを必要量確保し、
その確保したメモリがどこになるか示す
先頭のアドレスを返してくれる処理です。

// newIntの指す先(メモリ確保された箇所)は未初期化
int * newInt = new int;

// newIntの指す先(メモリ確保された個所)は0で初期化
int * newInt = new int();

// newIntの指す先(メモリ確保された箇所)は10で初期化
int * newInt = new int(10);

上記のように、
メモリ確保のやり方は複数あります。

配列を確保する場合
int * newArray = new int[100];

// メモリ確保に失敗したかどうかの判定もする場合。
int * newArray2 = new (std::nothrow) int[100];
if( newArray2 == nullptr )
{
	// メモリ不足
}

既存の型(charやintやfloatなど)だけでなく、
自分で作ったclassも、もちろんメモリ確保できる。
class Vector3D
{
public:
	Vector3D()
	{
		x = y = z = 0;  // 一括で同じ値で初期化するならこういう書き方も可能
	}
private:
	float x;
	float y;
	float z;
};

Vector3D * pVec3d = new Vector3D();
*/
/*
int main()
{
	// newIntの指す先(メモリ確保された箇所)は未初期化
	int* newInt = new int;

	// newIntの指す先(メモリ確保された個所)は0で初期化
	int* newInt2 = new int();

	// newIntの指す先(メモリ確保された箇所)は10で初期化
	int* newInt3 = new int(10);

	printf("newInt1 = %d\n", *newInt);
	printf("newInt2 = %d\n", *newInt2);
	printf("newInt3 = %d\n", *newInt3);

	delete newInt3;
	newInt3 = nullptr;  // この後処理はないので必要ないが癖付けの意味で書く
	delete newInt2;
	newInt2 = nullptr;
	delete newInt;
	newInt = nullptr;
}
*/
/*
delete
deleteはnewと対になる処理で、
確保しておいたメモリを解放します。
newでメモリを確保していた場合、必ずdeleteで解放する必要があります。

int * newInt = new int();
int * newArray = new int[100];

delete[] newArray;
newArray = nullptr;

delete newInt;
newInt = nullptr;

newはいろいろな確保のやり方がありましたが、
deleteは配列かそうでないかの2パターンになります。
deleteをした後のポインタ変数にnullptrを入れておいて、
現在どのアドレスも指していない=使用していない変数
ということを明示しておきましょう。
*/
/*
【問題】
メモリ確保を使用し、
1000個の配列を確保して、
その配列に0～999を設定するプログラムを作成してください。
*/

//int main()
//{
//    int* pArray = new int[1000];
//
//    for (int i = 0; i < 1000; ++i)
//    {
//        pArray[i] = i;
//    }
//
//    for (int i = 0; i < 1000; ++i)
//    {
//        printf("num = %d\n", pArray[i]);
//    }
//
//    delete[] pArray;
//    pArray = nullptr;
//}
/*
【問題】
先ほどのnewとdeleteで配列を確保する処理を、
クラスにしてデストラクタで自動でdeleteが呼ばれるようにしてください。
*/
#include <stdio.h>

class Array
{
	// ここを実装
private:
	int* pArray = nullptr;
	int pArraysize;
public:
	Array(int num)
	{
		pArray = new int[num];
		pArraysize = num;
	};

	~Array()
	{
		delete[] pArray;
		pArray = nullptr;
	};

	void SetArray(int num)
	{
		pArray[num] = num;
	};


	/*int Create(int num)
	{
		return pArray[num];
	}*/
	int Get(int num)
	{
		if (0 <= num && num < pArraysize)
		{
			return pArray[num];
		}
		else
		{
			printf("hoge");
			return 0;
		}
	}
};
int main()
{
	Array array(1000);

	//array.Create(1000);


	for (int i = 0; i < 1000; ++i)
	{
		array.SetArray(i);
		printf("num = %d\n", array.Get(i));
		
	}

	/*for (int i = 0; i < 1000; ++i)
	{
		
	}*/

	// 配列外参照しようとした際を確認
	printf("num = %d\n", array.Get(-1));
	printf("num = %d\n", array.Get(1000));
}

