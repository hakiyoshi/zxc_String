#pragma once
#include <cstdlib>
#include <string>

namespace zxc
{
	template<class std_string>
	class bace_string
	{
	public:
		static constexpr auto NPOS = std::string::npos;
		using value_string = std_string;
		using value_type = typename std_string::value_type;

	private:
		std_string m_str;

	public:
		//コンストラクタ、デストラクタ
		bace_string() = default;
		bace_string(const bace_string& str) = default;
		bace_string(bace_string&& str) noexcept = default;
		bace_string(std_string str) : m_str(std::move(str)){}
		bace_string(const value_type* str) : m_str(str){}
		bace_string(const value_type* str, size_t sizeType) : m_str(str, sizeType){}
		bace_string(size_t sizeType, value_type c) : m_str(sizeType, c) {}
		bace_string(value_type c) : m_str(1, c) {}
		bace_string(nullptr_t) = delete;
		~bace_string() = default;

		//operator=
		bace_string& operator=(const bace_string&) = default;
		bace_string& operator=(bace_string&&) = default;
		bace_string& operator=(const value_type* str){
			m_str = str;
			return *this;
		}
		bace_string& operator=(const std_string& str){
			m_str = str;
			return *this;
		}
		bace_string& operator=(std_string&& str){
			m_str = str;
			return *this;
		}
		bace_string& operator=(value_type c) {
			m_str = c;
			return *this;
		}

		operator std_string()const {
			return m_str;
		}

		//色々
		unsigned long long size()const noexcept { return m_str.size(); }//文字列の長さ
		unsigned long long length()const noexcept { return m_str.length(); }//文字列の長さ
		unsigned long long maxsize()const noexcept { return m_str.max_size(); }//格納可能な最大文字列長
		void resize(unsigned int size, value_type c) { m_str.resize(size, c); }//文字列の長さを変更する
		void resize(unsigned int size) { m_str.resize(size); }
		unsigned int capacity() const noexcept { return m_str.capacity(); }//メモリを再確保せずに格納できる最大の要素数を取得する
		void reserve(unsigned int capacity) { m_str.reserve(capacity); }//capacityを変更する
		void shrink_to_fit() { m_str.shrink_to_fit(); }//capacityをsizeまで変更する
		void clear()noexcept { m_str.clear(); }//文字列をクリアする
		bool empty() const noexcept { return m_str.empty(); }//文字列が空か判定する

		//begin,end系
		auto begin() { return m_str.begin(); }
		auto begin()const { return m_str.begin(); }
		auto end() { return m_str.end(); }
		auto end()const { return m_str.end(); }
		auto cbegin() { return m_str.cbegin(); }
		auto cbegin()const { return m_str.cbegin(); }
		auto cend() { return m_str.cend(); }
		auto cend()const { return m_str.cend(); }
		auto rbegin() { return m_str.rbegin(); }
		auto rbegin()const { return m_str.rbegin(); }
		auto rend() { return m_str.rend(); }
		auto rend()const { return m_str.rend(); }
		auto crbegin() { return m_str.crbegin(); }
		auto crbegin()const { return m_str.crbegin(); }
		auto crend() { return m_str.crend(); }
		auto crend()const { return m_str.crend(); }

		//要素にアクセス
		std_string str()const noexcept { return m_str; }//stdのstringで文字列を取得する
		const value_type* c_str()const noexcept { return m_str.c_str(); }//c言語の文字列表現で取得する

		value_type at(unsigned int pos)const { return m_str[pos]; }
		value_type at(unsigned int pos) { return m_str[pos]; }
		value_type operator[](unsigned int pos)const { return m_str[pos]; }
		value_type operator[](unsigned int pos) { return m_str[pos]; }

		value_type front()const { return m_str.front(); }
		value_type front() { return m_str.front(); }
		value_type back()const { return m_str.back(); }
		value_type back() { return m_str.back(); }

		//コピー
		unsigned long long copy(value_type* str, unsigned int n, unsigned int pos = 0)const{
			return m_str.copy(str, n, pos);
		}

		//最後に文字追加
		void push_back(value_type c) { m_str.push_back(c); }

		//文字、文字列追加
		bace_string& operator+=(const bace_string& str){//文字列追加
			m_str += str.m_str;
			return *this;
		}
		bace_string& operator+=(bace_string&& str){
			m_str += str.m_str;
			return *this;
		}
		bace_string& operator+=(const value_type* str){
			m_str += str;
			return *this;
		}
		bace_string& operator+=(value_type c){
			m_str += c;
			return *this;
		}

		bace_string& append(const bace_string& str){//文字列追加
			m_str.append(str.m_str);
			return *this;
		}
		bace_string& append(const std_string& str) {
			m_str.append(str);
			return *this;
		}

		bace_string& append(const bace_string& str, unsigned int pos, unsigned int n = NPOS) {//追加する文字列の開始位置と文字数を指定して
			m_str.append(str.m_str, pos, n);
			return *this;
		}
		bace_string& append(const std_string& str, unsigned int pos, unsigned int n = NPOS) {
			m_str.append(str, pos, n);
			return *this;
		}

		bace_string& append(const bace_string& str, unsigned int n = NPOS) {//追加する文字列の文字数を指定して追加
			m_str.append(str.m_str, n);
			return *this;
		}
		bace_string& append(const std_string& str, unsigned int n = NPOS) {
			m_str.append(str, n);
			return *this;
		}

		bace_string& append(value_type* str) {//文字列追加
			m_str.append(str);
			return *this;
		}

		bace_string& append(unsigned int n, value_type str) {//strの文字をn個分連続するように追加
			m_str.append(n, str);
			return *this;
		}


		//文字、文字列を上書き
		bace_string& assign(const bace_string& str){//文字列を上書き
			m_str.assign(str.m_str);
			return *this;
		}
		bace_string& assign(bace_string&& str)noexcept {
			m_str.assign(str.m_str);
			return *this;
		}
		bace_string& assign(const std_string& str) {
			m_str.assign(str);
			return *this;
		}

		bace_string& assign(const bace_string& str, unsigned int pos, unsigned int n = NPOS) {//上書きする文字列の位置と文字数を指定する
			m_str.assign(str.m_str, pos, n);
			return *this;
		}
		bace_string& assign(const std_string& str, unsigned int pos, unsigned int n = NPOS) {
			m_str.assign(str, pos, n);
			return *this;
		}

		bace_string& assign(const bace_string& str, unsigned int n = NPOS) {//上書きする文字列の文字数を指定する
			m_str.assign(str.m_str, n);
			return *this;
		}
		bace_string& assign(const std_string& str, unsigned int n = NPOS) {
			m_str.assign(str, n);
			return *this;
		}

		bace_string& assign(value_type* str) {//文字列上書き
			m_str.assign(str);
			return *this;
		}

		bace_string& assign(unsigned int n, value_type c) {//cで指定した文字をn個分連続になるように上書きする
			m_str.assign(n, c);
			return *this;
		}

		//文字、文字列を挿入する
		bace_string& insert(unsigned int pos1, const bace_string& str){//指定位置に文字列を挿入する
			m_str.insert(pos1, str.m_str);
			return *this;
		}
		bace_string& insert(unsigned int pos1, const std_string& str) {
			m_str.insert(pos1, str);
			return *this;
		}

		bace_string& insert(unsigned int pos1, const bace_string& str, unsigned int pos2, unsigned int n = NPOS){//指定位置に、部分文字列を挿入する
			m_str.insert(pos1, str.m_str, pos2, n);
			return *this;
		}
		bace_string& insert(unsigned int pos1, const std_string& str, unsigned int pos2, unsigned int n = NPOS) {
			m_str.insert(pos1, str, pos2, n);
			return *this;
		}

		bace_string& insert(unsigned int pos, value_type* str, unsigned int n){//指定位置に、文字配列の先頭N文字を挿入する
			m_str.insert(pos, str, n);
			return *this;
		}
		bace_string& insert(unsigned int pos, value_type* str){//指定位置に文字配列を挿入する
			m_str.insert(pos, str);
			return *this;
		}
		bace_string& insert(unsigned int pos, unsigned int n, value_type c){//指定位置に、N個の文字を挿入する
			m_str.insert(pos, n, c);
			return *this;
		}

		auto insert(const typename std_string::iterator& itr, value_type c){//指定したイテレータが指す要素の前に、文字を挿入する
			return m_str.insert(itr, c);
		}
		auto insert(const typename std_string::const_iterator& itr, value_type c) {
			return m_str.insert(itr, c);
		}

		auto insert(const typename std_string::iterator& itr, unsigned int n, value_type c) {//指定したイテレータが指す要素の前に、N個の文字を挿入する
			return m_str.insert(itr, n, c);
		}
		auto insert(const typename std_string::const_iterator& itr, unsigned int n, value_type c) {
			return m_str.insert(itr, n, c);
		}

		//要素を削除
		bace_string& erase(unsigned int pos = 0, unsigned int n = NPOS){//pos番目からn要素を削除する。
			m_str.erase(pos, n);
			return *this;
		}
		auto erase(const typename std_string::const_iterator& itr) { return m_str.erase(itr); }//イテレータpが指す要素を削除する
		auto erase(const typename std_string::const_iterator& first, const typename std_string::const_iterator& last) { return m_str.erase(first, last); }//イテレータ範囲[first, last)を削除する

		//末尾の一文字を削除する
		void pop_back() { m_str.pop_back(); }

		//文字列の一部を置き換える
		bace_string& replace(unsigned int pos1, unsigned int n1, const bace_string& str){//指定した位置からN文字を、文字列で置き換える
			m_str.replace(pos1, n1, str.m_str);
			return *this;
		}
		bace_string& replace(unsigned int pos1, unsigned int n1, const std_string& str) {
			m_str.replace(pos1, n1, str);
			return *this;
		}

		bace_string& replace(//指定した一からN文字を、文字列の一部で置き換える
			unsigned int pos1, unsigned int n1, const bace_string& str,
			unsigned int pos2, unsigned n2 = NPOS){
			m_str.replace(pos1, n1, str.m_str, pos2, n2);
			return *this;
		}
		bace_string& replace(
			unsigned int pos1, unsigned int n1, const std_string& str,
			unsigned int pos2, unsigned n2 = NPOS) {
			m_str.replace(pos1, n1, str, pos2, n2);
			return *this;
		}

		bace_string& replace(unsigned int pos, unsigned int n1, value_type* str, unsigned int n2){//指定した位置からN文字を、文字配列の先頭M文字で置き換える
			m_str.replace(pos, n1, str, n2);
			return *this;
		}
		bace_string& replace(unsigned int pos, unsigned int n1, value_type* str) {//指定した位置からN文字を、文字配列で置き換える
			m_str.replace(pos, n1, str);
			return *this;
		}
		bace_string& replace(unsigned int pos, unsigned int n1, unsigned int n2, value_type str) {//指定した位置からN文字を、M個の文字で置き換える
			m_str.replace(pos, n1, n2, str);
			return *this;
		}

		bace_string& replace(const typename std_string::iterator& i1, const typename std_string::iterator& i2, const bace_string& str){//指定したイテレータ範囲を、文字列で置き換える
			m_str.replace(i1, i2, str.m_str);
			return *this;
		}
		bace_string& replace(const typename std_string::const_iterator& i1, const typename std_string::const_iterator& i2, const bace_string& str) {
			m_str.replace(i1, i2, str.m_str);
			return *this;
		}
		bace_string& replace(const typename std_string::iterator& i1, const typename std_string::iterator& i2, const std_string& str) {
			m_str.replace(i1, i2, str);
			return *this;
		}
		bace_string& replace(const typename std_string::const_iterator& i1, const typename std_string::const_iterator& i2, const std_string& str) {
			m_str.replace(i1, i2, str);
			return *this;
		}

		bace_string& replace(const typename std_string::iterator& i1, const typename std_string::iterator& i2, value_type* str, unsigned int n){//指定したイテレータ範囲を、文字配列の先頭N文字で置き換える
			m_str.replace(i1, i2, str, n);
			return *this;
		}
		bace_string& replace(const typename std_string::const_iterator& i1, const typename std_string::const_iterator& i2, value_type* str, unsigned int n) {
			m_str.replace(i1, i2, str, n);
			return *this;
		}

		bace_string& replace(const typename std_string::iterator& i1, const typename std_string::iterator& i2, value_type* str) {//指定したイテレータ範囲を、文字配列で置き換える
			m_str.replace(i1, i2, str);
			return *this;
		}
		bace_string& replace(const typename std_string::const_iterator& i1, const typename std_string::const_iterator& i2, value_type* str) {
			m_str.replace(i1, i2, str);
			return *this;
		}

		bace_string& replace(const typename std_string::iterator& i1, const typename std_string::iterator& i2, unsigned int n, value_type c) {//指定したイテレータ範囲を、N個の文字で置き換える
			m_str.replace(i1, i2, n, c);
			return *this;
		}
		bace_string& replace(const typename std_string::const_iterator& i1, const typename std_string::const_iterator& i2, unsigned int n, value_type c) {
			m_str.replace(i1, i2, n, c);
			return *this;
		}

		//データを入れ替える
		void swap(bace_string& str)noexcept { m_str.swap(str.m_str); }

		//文字列を検索する
		unsigned long long find(const bace_string& str, unsigned int pos = 0)const noexcept{//pos 以降で最初に str と一致する位置を返す
			return m_str.find(str.m_str, pos);
		}
		unsigned long long find(const std_string& str, unsigned int pos = 0)const {
			return m_str.find(str, pos);
		}

		unsigned long long find(value_type* str, unsigned int pos, unsigned int n)const{//pos 以降で最初に s と一致する位置を返す。s は長さ n の文字列へのポインタである
			return m_str.find(str, pos, n);
		}
		unsigned long long find(value_type* str, unsigned int pos = 0)const {//NULL 終端の文字列を扱う
			return m_str.find(str, pos);
		}

		unsigned long long find(value_type c, unsigned int pos = 0)const{//pos 以降で最初に c と一致する位置を返す
			return m_str.find(c, pos);
		}

		//最後に現れる指定文字列を検索する
		unsigned long long rfind(const bace_string& str, unsigned int pos = NPOS) const noexcept {//pos 以前で最後に str と一致する位置を返す
			return m_str.rfind(str.m_str, pos);
		}
		unsigned long long rfind(const std_string& str, unsigned int pos = NPOS) const noexcept {
			return m_str.rfind(str, pos);
		}

		unsigned long long rfind(value_type* str, unsigned int pos, unsigned int n)const{//pos 以前で最後に s と一致する位置を返す。s は長さ n の文字列へのポインタである
			return m_str.rfind(str, pos, n);
		}
		unsigned long long rfind(value_type* str, unsigned int pos = NPOS)const {//NULL 終端の文字列を扱う
			return m_str.rfind(str, pos);
		}

		unsigned long long rfind(value_type c, unsigned int pos = NPOS)const{//pos 以前で最後に c と一致する位置を返す
			return m_str.rfind(c, pos);
		}

		//最初に現れる指定文字を検索する
		unsigned long long find_first_of(const bace_string& str, unsigned int pos = 0)const noexcept{//pos 以降で最初に str 内に存在する文字の位置を返す
			return m_str.find_first_of(str.m_str, pos);
		}
		unsigned long long find_first_of(const std_string& str, unsigned int pos = 0)const noexcept {
			return m_str.find_first_of(str, pos);
		}

		unsigned long long find_first_of(value_type* str, unsigned int pos, unsigned int n)const {//pos 以降で最初に s 内に存在する文字の位置を返す。s は長さ n の文字列へのポインタである
			return m_str.find_first_of(str, pos, n);
		}
		unsigned long long find_first_of(value_type* str, unsigned int pos = 0)const {// NULL 終端の文字列を扱う
			return m_str.find_first_of(str, pos);
		}

		unsigned long long find_first_of(value_type c, unsigned int pos = 0)const {//pos 以降で最初に c と一致する文字の位置を返す
			return m_str.find_first_of(c, pos);
		}

		//最後に現れる指定文字を検索する
		unsigned long long find_last_of(const bace_string& str, unsigned int pos = 0)const noexcept {//pos 以前で最初に str 内に存在する文字の位置を返す
			return m_str.find_last_of(str.m_str, pos);
		}
		unsigned long long find_last_of(const std_string& str, unsigned int pos = 0)const noexcept {
			return m_str.find_last_of(str, pos);
		}

		unsigned long long find_last_of(value_type* str, unsigned int pos, unsigned int n)const {//pos 以前で最初に s 内に存在する文字の位置を返す。s は長さ n の文字列へのポインタである
			return m_str.find_last_of(str, pos, n);
		}
		unsigned long long find_last_of(value_type* str, unsigned int pos = 0)const {// NULL 終端の文字列を扱う
			return m_str.find_last_of(str, pos);
		}

		unsigned long long find_last_of(value_type c, unsigned int pos = 0)const {//pos 以前で最初に c と一致する文字の位置を返す
			return m_str.find_last_of(c, pos);
		}

		//先頭から指定文字が見つからない位置を検索する
		unsigned long long find_first_not_of(const bace_string& str, unsigned int pos = 0)const noexcept {//pos 以降で最初に str 内に存在する文字の位置を返す
			return m_str.find_first_not_of(str.m_str, pos);
		}
		unsigned long long find_first_not_of(const std_string& str, unsigned int pos = 0)const noexcept {
			return m_str.find_first_not_of(str, pos);
		}

		unsigned long long find_first_not_of(value_type* str, unsigned int pos, unsigned int n)const {//pos 以降で最初に s 内に存在する文字の位置を返す。s は長さ n の文字列へのポインタである
			return m_str.find_first_not_of(str, pos, n);
		}
		unsigned long long find_first_not_of(value_type* str, unsigned int pos = 0)const {// NULL 終端の文字列を扱う
			return m_str.find_first_not_of(str, pos);
		}

		unsigned long long find_first_not_of(value_type c, unsigned int pos = 0)const {//pos 以降で最初に c と一致する文字の位置を返す
			return m_str.find_first_not_of(c, pos);
		}

		//末尾から、指定文字が見つからない位置を検索する
		unsigned long long find_last_not_of(const bace_string& str, unsigned int pos = 0)const noexcept {//pos 以前で最初に str 内に存在する文字の位置を返す
			return m_str.find_last_not_of(str.m_str, pos);
		}
		unsigned long long find_last_not_of(const std_string& str, unsigned int pos = 0)const noexcept {
			return m_str.find_last_not_of(str, pos);
		}

		unsigned long long find_last_not_of(value_type* str, unsigned int pos, unsigned int n)const {//pos 以前で最初に s 内に存在する文字の位置を返す。s は長さ n の文字列へのポインタである
			return m_str.find_last_not_of(str, pos, n);
		}
		unsigned long long find_last_not_of(value_type* str, unsigned int pos = 0)const {// NULL 終端の文字列を扱う
			return m_str.find_last_not_of(str, pos);
		}

		unsigned long long find_last_not_of(value_type c, unsigned int pos = 0)const {//pos 以前で最初に c と一致する文字の位置を返す
			return m_str.find_last_not_of(c, pos);
		}

		//部分文字列を取得する
		bace_string substr(unsigned int pos = 0, unsigned int n = NPOS)const{
			return m_str.substr(pos, n);
		}

		//他の文字列との比較を行う
		int compara(const bace_string& str)const noexcept{
			return m_str.compare(str.m_str);
		}
		int compara(const std_string& str)const noexcept {
			return m_str.compare(str);
		}
		int compara(const value_type* str)const noexcept {
			return m_str.compara(str);
		}

		//指定の文字、文字列で始まるかを判定する
		bool starts_with(value_type c)const noexcept{
			return m_str[0] == c;
		}
		bool starts_with(value_type* c)const noexcept{
			for (int i = 0; i < m_str.size(); ++i)
			{
				if (c[i] == '\0')
					return true;

				if (c[i] != m_str[i])
					return false;
			}

			return false;
		}

		//指定の文字列で終わるかを判定する
		bool ends_with(value_type c)const noexcept{
			return m_str[m_str.size() - 1] == c;
		}
		bool ends_with(value_type* c)const noexcept{
			//文字数カウント
			int len;
			for (len = 0; c[len] != '\0';)
				len++;

			//文字数が大きい場合
			if (len >= m_str.size())
				return false;

			for (int i = m_str.size() - 1; i >= 0; --i)
			{
				if (len - 1 < 0)
					return true;

				if (c[len - 1] != m_str[i])
					return false;

				len--;
			}

			return false;
		}

		bool contains(value_type c) const {
			return find(c) != NPOS;
		}
		bool contains(value_type* str) const {
			return find(str) != NPOS;
		}
	};

	//宣言
	using string = bace_string<std::string>;
	using wstring = bace_string<std::wstring>;


	//to_string
	static string to_string(int value) { return std::to_string(value); }
	static string to_string(unsigned int value) { return std::to_string(value); }
	static string to_string(long value) { return std::to_string(value); }
	static string to_string(unsigned long value) { return std::to_string(value); }
	static string to_string(long long value) { return std::to_string(value); }
	static string to_string(unsigned long long value) { return std::to_string(value); }
	static string to_string(float value) { return std::to_string(value); }
	static string to_string(double value) { return std::to_string(value); }
	static string to_string(long double value) { return std::to_string(value); }

	//to_wstring
	static wstring to_wstring(int value) { return std::to_wstring(value); }
	static wstring to_wstring(unsigned int value) { return std::to_wstring(value); }
	static wstring to_wstring(long value) { return std::to_wstring(value); }
	static wstring to_wstring(unsigned long value) { return std::to_wstring(value); }
	static wstring to_wstring(long long value) { return std::to_wstring(value); }
	static wstring to_wstring(unsigned long long value) { return std::to_wstring(value); }
	static wstring to_wstring(float value) { return std::to_wstring(value); }
	static wstring to_wstring(double value) { return std::to_wstring(value); }
	static wstring to_wstring(long double value) { return std::to_wstring(value); }

	//string string
	template<class std_string>
	bace_string<std_string> operator+(const bace_string<std_string>& ls, const bace_string<std_string>& rs) { return bace_string<std_string>(ls) += rs; }
	template<class std_string>
	bace_string<std_string> operator+(bace_string<std_string>&& ls, bace_string<std_string>&& rs) { return ls += rs; }

	//char* string
	template<class std_string>
	bace_string<std_string> operator+(const typename bace_string<std_string>::value_type* ls, const bace_string<std_string>& rs) { return bace_string<std_string>(ls) += rs; }
	template<class std_string>
	bace_string<std_string> operator+(const bace_string<std_string>& ls, const typename bace_string<std_string>::value_type* rs) { return bace_string<std_string>(ls) += rs; }

	template<class std_string>
	bace_string<std_string> operator+(const typename bace_string<std_string>::value_type* ls, bace_string<std_string>&& rs) { return bace_string<std_string>(ls) += rs; }
	template<class std_string>
	bace_string<std_string> operator+(bace_string<std_string>&& ls, const typename bace_string<std_string>::value_type* rs) { return bace_string<std_string>(ls) += rs; }

	//std::string string
	template<class std_string>
	bace_string<std_string> operator+(const std_string& ls, const bace_string<std_string>& rs) { return bace_string<std_string>(ls) += rs; }
	template<class std_string>
	bace_string<std_string> operator+(const bace_string<std_string>& ls, const std_string& rs) { return bace_string<std_string>(ls) += rs; }

	template<class std_string>
	bace_string<std_string> operator+(std_string&& ls, bace_string<std_string>&& rs) { return bace_string<std_string>(ls) += rs; }
	template<class std_string>
	bace_string<std_string> operator+(bace_string<std_string>&& ls, std_string&& rs) { return bace_string<std_string>(ls) += rs; }


	//int string
	inline string operator+(int lv, const string& rs) { return string(to_string(lv)) += rs; }
	inline string operator+(const string& ls, int rv) { return string(ls) += to_string(rv); }
	inline wstring operator+(int lv, const wstring& rs) { return wstring(to_wstring(lv)) += rs; }
	inline wstring operator+(const wstring& ls, int rv) { return wstring(ls) += to_wstring(rv); }

	//uint string
	inline string operator+(unsigned int lv, const string& rs) { return string(to_string(lv)) += rs; }
	inline string operator+(const string& ls, unsigned int rv) { return string(ls) += to_string(rv); }
	inline wstring operator+(unsigned int lv, const wstring& rs) { return wstring(to_wstring(lv)) += rs; }
	inline wstring operator+(const wstring& ls, unsigned int rv) { return wstring(ls) += to_wstring(rv); }

	////long string
	inline string operator+(long lv, const string& rs) { return string(to_string(lv)) += rs; }
	inline string operator+(const string& ls, long rv) { return string(ls) += to_string(rv); }
	inline wstring operator+(long lv, const wstring& rs) { return wstring(to_wstring(lv)) += rs; }
	inline wstring operator+(const wstring& ls, long rv) { return wstring(ls) += to_wstring(rv); }

	////ulong string
	inline string operator+(unsigned long lv, const string& rs) { return string(to_string(lv)) += rs; }
	inline string operator+(const string& ls, unsigned long rv) { return string(ls) += to_string(rv); }
	inline wstring operator+(unsigned long lv, const wstring& rs) { return wstring(to_wstring(lv)) += rs; }
	inline wstring operator+(const wstring& ls, unsigned long rv) { return wstring(ls) += to_wstring(rv); }

	////long long string
	inline string operator+(long long lv, const string& rs) { return string(to_string(lv)) += rs; }
	inline string operator+(const string& ls, long long rv) { return string(ls) += to_string(rv); }
	inline wstring operator+(long long lv, const wstring& rs) { return wstring(to_wstring(lv)) += rs; }
	inline wstring operator+(const wstring& ls, long long rv) { return wstring(ls) += to_wstring(rv); }

	////ulong long string
	inline string operator+(unsigned long long lv, const string& rs) { return string(to_string(lv)) += rs; }
	inline string operator+(const string& ls, unsigned long long rv) { return string(ls) += to_string(rv); }
	inline wstring operator+(unsigned long long lv, const wstring& rs) { return wstring(to_wstring(lv)) += rs; }
	inline wstring operator+(const wstring& ls, unsigned long long rv) { return wstring(ls) += to_wstring(rv); }

	////float string
	inline string operator+(float lv, const string& rs) { return string(to_string(lv)) += rs; }
	inline string operator+(const string& ls, float rv) { return string(ls) += to_string(rv); }
	inline wstring operator+(float lv, const wstring& rs) { return wstring(to_wstring(lv)) += rs; }
	inline wstring operator+(const wstring& ls, float rv) { return wstring(ls) += to_wstring(rv); }

	////double string
	inline string operator+(double lv, const string& rs) { return string(to_string(lv)) += rs; }
	inline string operator+(const string& ls, double rv) { return string(ls) += to_string(rv); }
	inline wstring operator+(double lv, const wstring& rs) { return wstring(to_wstring(lv)) += rs; }
	inline wstring operator+(const wstring& ls, double rv) { return wstring(ls) += to_wstring(rv); }

	////long double string
	inline string operator+(long double lv, const string& rs) { return string(to_string(lv)) += rs; }
	inline string operator+(const string& ls, long double rv) { return string(ls) += to_string(rv); }
	inline wstring operator+(long double lv, const wstring& rs) { return wstring(to_wstring(lv)) += rs; }
	inline wstring operator+(const wstring& ls, long double rv) { return wstring(ls) += to_wstring(rv); }

	//operator==
	template<class std_string>
	bace_string<std_string> operator==(const bace_string<std_string>& ls, const bace_string<std_string>& rs)noexcept { return ls.compara(rs) == 0; }
	template<class std_string>
	bace_string<std_string> operator==(const typename bace_string<std_string>::value_type* ls, const bace_string<std_string>& rs) { return ls == rs; }
	template<class std_string>
	bace_string<std_string> operator==(const bace_string<std_string>& ls, const typename bace_string<std_string>::value_type* rs) { return ls.compara(rs) == 0; }

	//operator!=
	template<class std_string>
	bace_string<std_string> operator!=(const bace_string<std_string>& ls, const bace_string<std_string>& rs)noexcept { return ls.compara(rs) != 0; }
	template<class std_string>
	bace_string<std_string> operator!=(const typename bace_string<std_string>::value_type* ls, const bace_string<std_string>& rs) { return ls != rs; }
	template<class std_string>
	bace_string<std_string> operator!=(const bace_string<std_string>& ls, const typename bace_string<std_string>::value_type* rs) { return ls.compara(rs) != 0; }

	//operator<
	template<class std_string>
	bace_string<std_string> operator<(const bace_string<std_string>& ls, const bace_string<std_string>& rs)noexcept { return ls.size() < rs.size(); }
	template<class std_string>
	bace_string<std_string> operator<(const typename bace_string<std_string>::value_type* ls, const bace_string<std_string>& rs) { return rs.compara(ls) > 0; }
	template<class std_string>
	bace_string<std_string> operator<(const bace_string<std_string>& ls, const typename bace_string<std_string>::value_type* rs) { return ls.compara(rs) < 0; }

	//operator<=
	template<class std_string>
	bace_string<std_string> operator<=(const bace_string<std_string>& ls, const bace_string<std_string>& rs)noexcept { return ls.size() <= rs.size(); }
	template<class std_string>
	bace_string<std_string> operator<=(const typename bace_string<std_string>::value_type* ls, const bace_string<std_string>& rs) { return rs.compara(ls) >= 0; }
	template<class std_string>
	bace_string<std_string> operator<=(const bace_string<std_string>& ls, const typename bace_string<std_string>::value_type* rs) { return ls.compara(rs) <= 0; }

	//operator>
	template<class std_string>
	bace_string<std_string> operator>(const bace_string<std_string>& ls, const bace_string<std_string>& rs)noexcept { return ls.size() > rs.size(); }
	template<class std_string>
	bace_string<std_string> operator>(const typename bace_string<std_string>::value_type* ls, const bace_string<std_string>& rs) { return rs.compara(ls) < 0; }
	template<class std_string>
	bace_string<std_string> operator>(const bace_string<std_string>& ls, const typename bace_string<std_string>::value_type* rs) { return ls.compara(rs) > 0; }

	//operator>=
	template<class std_string>
	bace_string<std_string> operator>=(const bace_string<std_string>& ls, const bace_string<std_string>& rs)noexcept { return ls.size() >= rs.size(); }
	template<class std_string>
	bace_string<std_string> operator>=(const typename bace_string<std_string>::value_type* ls, const bace_string<std_string>& rs) { return rs.compara(ls) <= 0; }
	template<class std_string>
	bace_string<std_string> operator>=(const bace_string<std_string>& ls, const typename bace_string<std_string>::value_type* rs) { return ls.compara(rs) >= 0; }

	//swap
	template<class std_string>
	void swap(bace_string<std_string>& ls, bace_string<std_string>& rs) noexcept { ls.swap(rs); }

	//erase
	template<class std_string, class U>
	bace_string<std_string>& erase(bace_string<std_string>& str, const U& value) {
		auto it = std::remove(str.begin(), str.end(), value);
		str.erase(it, str.end());
		return str;
	}

	//erase_if
	template<class std_string, class Predicate>
	bace_string<std_string>& erase_if(bace_string<std_string>& str, Predicate pred) {
		auto it = std::remove_if(str.begin(), str.end(), pred);
		str.erase(it, str.end());
		return str;
	}

	inline wstring convString(const string& str) {
		size_t i;
		wchar_t* buffer = new wchar_t[str.size() + 1];
		mbstowcs_s(&i, buffer, str.size() + 1, str.c_str(), _TRUNCATE);
		wstring wstr(buffer);
		delete[] buffer;
		return wstr;
	}

	inline string convWString(const wstring& wstr) {
		size_t i;
		char* buffer = new char[wstr.size() * MB_CUR_MAX + 1];
		wcstombs_s(&i, buffer, wstr.size() * MB_CUR_MAX + 1, wstr.c_str(), _TRUNCATE);
		string str = buffer;
		delete[] buffer;
		return str;
	}
}
