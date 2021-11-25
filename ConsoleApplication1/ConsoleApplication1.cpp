int main()
{
	const char* f = "12345";
	int a = f;//エラー
	int b = (int)f;//C言語のキャスト演算子をそのまま使用
	int c = reinterpret_cast<int>(f);
	int d = int(f   );

}
