#include <stdio.h>

/*
�I�u�W�F�N�g�̐����Ɣj��
C++�ł̓������m�ۂ�new/delete���g�����Ƃōs�����Ƃ��ł���B
�܂��́A�������m�ۂ̂����ȑO�ɁA
�Ȃ��������m�ۂ�K�v�Ƃ���̂��b���Ă����܂��B
*/

/*
�Ȃ��������m�ۂ��K�v�Ȃ̂�
�Q�[���Ɍ��炸�A���ׂẴA�v���P�[�V�����ɂ����āA
�c��ȃf�[�^�������A�v���P�[�V�����͂��̂��ׂẴf�[�^���A
��������ɓW�J���邱�Ƃ͂ł��Ȃ��B
�Ȃ��Ȃ�A���������L��������ł��B
�������������ł���΁A�������m�ۂ��g���K�v�͂���܂���B
�������A�����I�Ƀ������������Ƃ������Ƃ͂Ȃ��̂ŁA
�������m�ۂ̋@�\�𗘗p���A
�����������̃^�C�~���O�ɕK�v�ȗʂ����g���A
�Ƃ������Ƃ��ł���̂ŁA
�������m�ۂ̓������������ɂȂ�܂ł́A
�K�v�ȋZ�p�ɂȂ�܂��B

�����b�g:
�L���ȃ��������A���̎��X�ɕK�v�ȗʂ����g�����Ƃ��ł���B

�f�����b�g�F
�m�ۂ����������̉����Y���ƁA���������[�N���āA�o�O�̌����ɂȂ�B
���������������m�ۂ̏����͏d�����B
*/

/*
new
new�̏����̓�������K�v�ʊm�ۂ��A
���̊m�ۂ������������ǂ��ɂȂ邩����
�擪�̃A�h���X��Ԃ��Ă���鏈���ł��B

// newInt�̎w����(�������m�ۂ��ꂽ�ӏ�)�͖�������
int * newInt = new int;

// newInt�̎w����(�������m�ۂ��ꂽ��)��0�ŏ�����
int * newInt = new int();

// newInt�̎w����(�������m�ۂ��ꂽ�ӏ�)��10�ŏ�����
int * newInt = new int(10);

��L�̂悤�ɁA
�������m�ۂ̂����͕�������܂��B

�z����m�ۂ���ꍇ
int * newArray = new int[100];

// �������m�ۂɎ��s�������ǂ����̔��������ꍇ�B
int * newArray2 = new (std::nothrow) int[100];
if( newArray2 == nullptr )
{
	// �������s��
}

�����̌^(char��int��float�Ȃ�)�����łȂ��A
�����ō����class���A������񃁃����m�ۂł���B
class Vector3D
{
public:
	Vector3D()
	{
		x = y = z = 0;  // �ꊇ�œ����l�ŏ���������Ȃ炱���������������\
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
	// newInt�̎w����(�������m�ۂ��ꂽ�ӏ�)�͖�������
	int* newInt = new int;

	// newInt�̎w����(�������m�ۂ��ꂽ��)��0�ŏ�����
	int* newInt2 = new int();

	// newInt�̎w����(�������m�ۂ��ꂽ�ӏ�)��10�ŏ�����
	int* newInt3 = new int(10);

	printf("newInt1 = %d\n", *newInt);
	printf("newInt2 = %d\n", *newInt2);
	printf("newInt3 = %d\n", *newInt3);

	delete newInt3;
	newInt3 = nullptr;  // ���̌㏈���͂Ȃ��̂ŕK�v�Ȃ����ȕt���̈Ӗ��ŏ���
	delete newInt2;
	newInt2 = nullptr;
	delete newInt;
	newInt = nullptr;
}
*/
/*
delete
delete��new�Ƒ΂ɂȂ鏈���ŁA
�m�ۂ��Ă�������������������܂��B
new�Ń��������m�ۂ��Ă����ꍇ�A�K��delete�ŉ������K�v������܂��B

int * newInt = new int();
int * newArray = new int[100];

delete[] newArray;
newArray = nullptr;

delete newInt;
newInt = nullptr;

new�͂��낢��Ȋm�ۂ̂���������܂������A
delete�͔z�񂩂����łȂ�����2�p�^�[���ɂȂ�܂��B
delete��������̃|�C���^�ϐ���nullptr�����Ă����āA
���݂ǂ̃A�h���X���w���Ă��Ȃ�=�g�p���Ă��Ȃ��ϐ�
�Ƃ������Ƃ𖾎����Ă����܂��傤�B
*/
/*
�y���z
�������m�ۂ��g�p���A
1000�̔z����m�ۂ��āA
���̔z���0�`999��ݒ肷��v���O�������쐬���Ă��������B
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
�y���z
��قǂ�new��delete�Ŕz����m�ۂ��鏈�����A
�N���X�ɂ��ăf�X�g���N�^�Ŏ�����delete���Ă΂��悤�ɂ��Ă��������B
*/
#include <stdio.h>

class Array
{
	// ����������
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

	// �z��O�Q�Ƃ��悤�Ƃ����ۂ��m�F
	printf("num = %d\n", array.Get(-1));
	printf("num = %d\n", array.Get(1000));
}

