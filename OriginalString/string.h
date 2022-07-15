#pragma once
#include <string>

namespace ghl
{
	class string
	{
	private:
		using control_string = std::string;

	private:
		control_string m_str;

	public:
		//コンストラクタ、デストラクタ
		string() = default;
		string(const string& str) = default;
		string(string&& str) noexcept = default;
		string(control_string str) : m_str(std::move(str)){}
		string(control_string& str) : m_str(str){}
		string(const char* str) : m_str(str){}
		string(const char* str, size_t sizeType) : m_str(str, sizeType){}
		string(size_t sizeType, const char* str) : m_str(str, sizeType) {}
		string(nullptr_t) = delete;
		~string() = default;

		//operator=
		string& operator=(const string&) = default;
		string& operator=(string&&) = default;
		string& operator=(const char* str){
			m_str = str;
			return *this;
		}
		string& operator=(const control_string& str){
			m_str = str;
			return *this;
		}
		string& operator=(control_string&& str){
			m_str = str;
			return *this;
		}

		//色々
		unsigned int length()const noexcept { return m_str.length(); }//文字列の長さ
		unsigned int maxsize()const noexcept { return m_str.max_size(); }//格納可能な最大文字列長
		void resize(unsigned int size, char c) { m_str.resize(size, c); }//文字列の長さを変更する
		void resize(unsigned int size) { m_str.resize(size); }
		unsigned int capacity() const noexcept { return m_str.capacity(); }//メモリを再確保せずに格納できる最大の要素数を取得する
		void reserve(unsigned int capacity) { m_str.reserve(capacity); }//capacityを変更する
		void shrink_to_fit() { m_str.shrink_to_fit(); }//capacityをsizeまで変更する
		void clear()noexcept { m_str.clear(); }//文字列をクリアする
		bool empty()noexcept { return m_str.empty(); }//文字列が空か判定する

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
		control_string str()const noexcept { return m_str; }//stdのstringで文字列を取得する
		const char* c_str()const noexcept { return m_str.c_str(); }//c言語の文字列表現で取得する

		char at(unsigned int pos)const { return m_str[pos]; }
		char at(unsigned int pos) { return m_str[pos]; }
		char operator[](unsigned int pos)const { return m_str[pos]; }
		char operator[](unsigned int pos) { return m_str[pos]; }

		char front()const { return m_str.front(); }
		char front() { return m_str.front(); }
		char back()const { return m_str.back(); }
		char back() { return m_str.back(); }

		//コピー
		unsigned int copy(char* str, unsigned int n, unsigned int pos = 0)const{
			return m_str.copy(str, n, pos);
		}

		//最後に文字追加
		void push_back(char c) { m_str.push_back(c); }

		//文字、文字列追加
		string& operator+=(const string& str){//文字列追加
			m_str += str.m_str;
			return *this;
		}
		string& operator+=(const control_string& str) {
			m_str += str;
			return *this;
		}
		string& operator+=(const char* str){
			m_str += str;
			return *this;
		}

		string& operator+=(char c){//文字追加
			m_str += c;
			return *this;
		}

		string& append(const string& str){//文字列追加
			m_str.append(str.m_str);
			return *this;
		}
		string& append(const control_string& str) {
			m_str.append(str);
			return *this;
		}

		string& append(const string& str, unsigned int pos, unsigned int n = control_string::npos) {//追加する文字列の開始位置と文字数を指定して
			m_str.append(str.m_str, pos, n);
			return *this;
		}
		string& append(const control_string& str, unsigned int pos, unsigned int n = control_string::npos) {
			m_str.append(str, pos, n);
			return *this;
		}

		string& append(const string& str, unsigned int n = control_string::npos) {//追加する文字列の文字数を指定して追加
			m_str.append(str.m_str, n);
			return *this;
		}
		string& append(const control_string& str, unsigned int n = control_string::npos) {
			m_str.append(str, n);
			return *this;
		}

		string& append(const char* str) {//文字列追加
			m_str.append(str);
			return *this;
		}

		string& append(unsigned int n, char str) {//strの文字をn個分連続するように追加
			m_str.append(n, str);
			return *this;
		}


		//文字、文字列を上書き
		string& assign(const string& str){//文字列を上書き
			m_str.assign(str.m_str);
			return *this;
		}
		string& assign(string&& str)noexcept {
			m_str.assign(str.m_str);
			return *this;
		}
		string& assign(const control_string& str) {
			m_str.assign(str);
			return *this;
		}

		string& assign(const string& str, unsigned int pos, unsigned int n = control_string::npos) {//上書きする文字列の位置と文字数を指定する
			m_str.assign(str.m_str, pos, n);
			return *this;
		}
		string& assign(const control_string& str, unsigned int pos, unsigned int n = control_string::npos) {
			m_str.assign(str, pos, n);
			return *this;
		}

		string& assign(const string& str, unsigned int n = control_string::npos) {//上書きする文字列の文字数を指定する
			m_str.assign(str.m_str, n);
			return *this;
		}
		string& assign(const control_string& str, unsigned int n = control_string::npos) {
			m_str.assign(str, n);
			return *this;
		}

		string& assign(const char* str) {//文字列上書き
			m_str.assign(str);
			return *this;
		}

		string& assign(unsigned int n, char c) {//cで指定した文字をn個分連続になるように上書きする
			m_str.assign(n, c);
			return *this;
		}

		//文字、文字列を挿入する
		string& insert(unsigned int pos1, const string& str){//指定位置に文字列を挿入する
			m_str.insert(pos1, str.m_str);
			return *this;
		}
		string& insert(unsigned int pos1, const control_string& str) {
			m_str.insert(pos1, str);
			return *this;
		}

		string& insert(unsigned int pos1, const string& str, unsigned int pos2, unsigned int n = control_string::npos){//指定位置に、部分文字列を挿入する
			m_str.insert(pos1, str.m_str, pos2, n);
			return *this;
		}
		string& insert(unsigned int pos1, const control_string& str, unsigned int pos2, unsigned int n = control_string::npos) {
			m_str.insert(pos1, str, pos2, n);
			return *this;
		}

		string& insert(unsigned int pos, const char* str, unsigned int n)//指定位置に、文字配列の先頭N文字を挿入する
		{
			m_str.insert(pos, str, n);
			return *this;
		}
		string& insert(unsigned int pos, const char* str)//指定位置に文字配列を挿入する
		{
			m_str.insert(pos, str);
			return *this;
		}
		string& insert(unsigned int pos, unsigned int n, char c){//指定位置に、N個の文字を挿入する
			m_str.insert(pos, n, c);
			return *this;
		}

		auto insert(control_string::iterator itr, char c){//指定したイテレータが指す要素の前に、文字を挿入する
			return m_str.insert(itr, c);
		}
		auto insert(control_string::const_iterator itr, char c) {
			return m_str.insert(itr, c);
		}

		auto insert(control_string::iterator itr, unsigned int n, char c) {//指定したイテレータが指す要素の前に、N個の文字を挿入する
			return m_str.insert(itr, n, c);
		}
		auto insert(control_string::const_iterator itr, unsigned int n, char c) {
			return m_str.insert(itr, n, c);
		}

		//要素を削除
		string& erase(unsigned int pos = 0, unsigned int n = control_string::npos){//pos番目からn要素を削除する。
			m_str.erase(pos, n);
			return *this;
		}
		auto erase(control_string::const_iterator itr) { return m_str.erase(itr); }//イテレータpが指す要素を削除する
		auto erase(control_string::const_iterator first, control_string::const_iterator last) { return m_str.erase(first, last); }//イテレータ範囲[first, last)を削除する

		//末尾の一文字を削除する
		void pop_back() { m_str.pop_back(); }

		//文字列の一部を置き換える
		string& replace(unsigned int pos1, unsigned int n1, const string& str){//指定した位置からN文字を、文字列で置き換える
			m_str.replace(pos1, n1, str.m_str);
			return *this;
		}
		string& replace(unsigned int pos1, unsigned int n1, const control_string& str) {
			m_str.replace(pos1, n1, str);
			return *this;
		}

		string& replace(//指定した一からN文字を、文字列の一部で置き換える
			unsigned int pos1, unsigned int n1, const string& str,
			unsigned int pos2, unsigned n2 = control_string::npos){
			m_str.replace(pos1, n1, str.m_str, pos2, n2);
			return *this;
		}
		string& replace(
			unsigned int pos1, unsigned int n1, const control_string& str,
			unsigned int pos2, unsigned n2 = control_string::npos) {
			m_str.replace(pos1, n1, str, pos2, n2);
			return *this;
		}

		string& replace(unsigned int pos, unsigned int n1, const char* str, unsigned int n2){//指定した位置からN文字を、文字配列の先頭M文字で置き換える
			m_str.replace(pos, n1, str, n2);
			return *this;
		}
		string& replace(unsigned int pos, unsigned int n1, const char* str) {//指定した位置からN文字を、文字配列で置き換える
			m_str.replace(pos, n1, str);
			return *this;
		}
		string& replace(unsigned int pos, unsigned int n1, unsigned int n2, char str) {//指定した位置からN文字を、M個の文字で置き換える
			m_str.replace(pos, n1, n2, str);
			return *this;
		}

		string& replace(control_string::iterator i1, control_string::iterator i2, const string& str){//指定したイテレータ範囲を、文字列で置き換える
			m_str.replace(i1, i2, str.m_str);
			return *this;
		}
		string& replace(control_string::const_iterator i1, control_string::const_iterator i2, const string& str) {
			m_str.replace(i1, i2, str.m_str);
			return *this;
		}
		string& replace(control_string::iterator i1, control_string::iterator i2, const control_string& str) {
			m_str.replace(i1, i2, str);
			return *this;
		}
		string& replace(control_string::const_iterator i1, control_string::const_iterator i2, const control_string& str) {
			m_str.replace(i1, i2, str);
			return *this;
		}

		string& replace(control_string::iterator i1, control_string::iterator i2, const char* str, unsigned int n){//指定したイテレータ範囲を、文字配列の先頭N文字で置き換える
			m_str.replace(i1, i2, str, n);
			return *this;
		}
		string& replace(control_string::const_iterator i1, control_string::const_iterator i2, const char* str, unsigned int n) {
			m_str.replace(i1, i2, str, n);
			return *this;
		}

		string& replace(control_string::iterator i1, control_string::iterator i2, const char* str) {//指定したイテレータ範囲を、文字配列で置き換える
			m_str.replace(i1, i2, str);
			return *this;
		}
		string& replace(control_string::const_iterator i1, control_string::const_iterator i2, const char* str) {
			m_str.replace(i1, i2, str);
			return *this;
		}

		string& replace(control_string::iterator i1, control_string::iterator i2, unsigned int n, char c) {//指定したイテレータ範囲を、N個の文字で置き換える
			m_str.replace(i1, i2, n, c);
			return *this;
		}
		string& replace(control_string::const_iterator i1, control_string::const_iterator i2, unsigned int n, char c) {
			m_str.replace(i1, i2, n, c);
			return *this;
		}

		//データを入れ替える
		void swap(string& str)noexcept { m_str.swap(str.m_str); }

		//文字列を検索する
		unsigned int find(const string& str, unsigned int pos = 0)const noexcept{//pos 以降で最初に str と一致する位置を返す
			return m_str.find(str.m_str, pos);
		}
		unsigned int find(const control_string& str, unsigned int pos = 0)const {
			return m_str.find(str, pos);
		}

		unsigned int find(const char* str, unsigned int pos, unsigned int n)const{//pos 以降で最初に s と一致する位置を返す。s は長さ n の文字列へのポインタである
			return m_str.find(str, pos, n);
		}
		unsigned int find(const char* str, unsigned int pos = 0)const {//NULL 終端の文字列を扱う
			return m_str.find(str, pos);
		}

		unsigned int find(char c, unsigned int pos = 0)const{//pos 以降で最初に c と一致する位置を返す
			return m_str.find(c, pos);
		}

		//最後に現れる指定文字列を検索する
		unsigned int rfind(const string str, unsigned int pos = control_string::npos)noexcept {//pos 以前で最後に str と一致する位置を返す
			return m_str.rfind(str.m_str, pos);
		}
		unsigned int rfind(const control_string str, unsigned int pos = control_string::npos)noexcept {
			return m_str.rfind(str, pos);
		}

		unsigned int rfind(const char* str, unsigned int pos, unsigned int n)const{//pos 以前で最後に s と一致する位置を返す。s は長さ n の文字列へのポインタである
			return m_str.rfind(str, pos, n);
		}
		unsigned int rfind(const char* str, unsigned int pos = control_string::npos)const {//NULL 終端の文字列を扱う
			return m_str.rfind(str, pos);
		}

		unsigned int rfind(char c, unsigned int pos = control_string::npos)const{//pos 以前で最後に c と一致する位置を返す
			return m_str.rfind(c, pos);
		}

		//最初に現れる指定文字を検索する
		unsigned int find_first_of(const string& str, unsigned int pos = 0)const noexcept{//pos 以降で最初に str 内に存在する文字の位置を返す
			return m_str.find_first_of(str.m_str, pos);
		}
		unsigned int find_first_of(const control_string& str, unsigned int pos = 0)const noexcept {
			return m_str.find_first_of(str, pos);
		}

		unsigned int find_first_of(const char* str, unsigned int pos, unsigned int n)const {//pos 以降で最初に s 内に存在する文字の位置を返す。s は長さ n の文字列へのポインタである
			return m_str.find_first_of(str, pos, n);
		}
		unsigned int find_first_of(const char* str, unsigned int pos = 0)const {// NULL 終端の文字列を扱う
			return m_str.find_first_of(str, pos);
		}

		unsigned int find_first_of(char c, unsigned int pos = 0)const {//pos 以降で最初に c と一致する文字の位置を返す
			return m_str.find_first_of(c, pos);
		}

		//最後に現れる指定文字を検索する
		unsigned int find_last_of(const string& str, unsigned int pos = 0)const noexcept {//pos 以前で最初に str 内に存在する文字の位置を返す
			return m_str.find_last_of(str.m_str, pos);
		}
		unsigned int find_last_of(const control_string& str, unsigned int pos = 0)const noexcept {
			return m_str.find_last_of(str, pos);
		}

		unsigned int find_last_of(const char* str, unsigned int pos, unsigned int n)const {//pos 以前で最初に s 内に存在する文字の位置を返す。s は長さ n の文字列へのポインタである
			return m_str.find_last_of(str, pos, n);
		}
		unsigned int find_last_of(const char* str, unsigned int pos = 0)const {// NULL 終端の文字列を扱う
			return m_str.find_last_of(str, pos);
		}

		unsigned int find_last_of(char c, unsigned int pos = 0)const {//pos 以前で最初に c と一致する文字の位置を返す
			return m_str.find_last_of(c, pos);
		}

		//先頭から指定文字が見つからない位置を検索する
		unsigned int find_first_not_of(const string& str, unsigned int pos = 0)const noexcept {//pos 以降で最初に str 内に存在する文字の位置を返す
			return m_str.find_first_not_of(str.m_str, pos);
		}
		unsigned int find_first_not_of(const control_string& str, unsigned int pos = 0)const noexcept {
			return m_str.find_first_not_of(str, pos);
		}

		unsigned int find_first_not_of(const char* str, unsigned int pos, unsigned int n)const {//pos 以降で最初に s 内に存在する文字の位置を返す。s は長さ n の文字列へのポインタである
			return m_str.find_first_not_of(str, pos, n);
		}
		unsigned int find_first_not_of(const char* str, unsigned int pos = 0)const {// NULL 終端の文字列を扱う
			return m_str.find_first_not_of(str, pos);
		}

		unsigned int find_first_not_of(char c, unsigned int pos = 0)const {//pos 以降で最初に c と一致する文字の位置を返す
			return m_str.find_first_not_of(c, pos);
		}

		//末尾から、指定文字が見つからない位置を検索する
		unsigned int find_last_not_of(const string& str, unsigned int pos = 0)const noexcept {//pos 以前で最初に str 内に存在する文字の位置を返す
			return m_str.find_last_not_of(str.m_str, pos);
		}
		unsigned int find_last_not_of(const control_string& str, unsigned int pos = 0)const noexcept {
			return m_str.find_last_not_of(str, pos);
		}

		unsigned int find_last_not_of(const char* str, unsigned int pos, unsigned int n)const {//pos 以前で最初に s 内に存在する文字の位置を返す。s は長さ n の文字列へのポインタである
			return m_str.find_last_not_of(str, pos, n);
		}
		unsigned int find_last_not_of(const char* str, unsigned int pos = 0)const {// NULL 終端の文字列を扱う
			return m_str.find_last_not_of(str, pos);
		}

		unsigned int find_last_not_of(char c, unsigned int pos = 0)const {//pos 以前で最初に c と一致する文字の位置を返す
			return m_str.find_last_not_of(c, pos);
		}

		//部分文字列を取得する
		string substr(unsigned int pos = 0, unsigned int n = std::string::npos)const{
			return m_str.substr(pos, n);
		}

		//他の文字列との比較を行う
		int compara(const string& str)const noexcept{
			return m_str.compare(str.m_str);
		}
		int compara(const control_string& str)const noexcept {
			return m_str.compare(str);
		}

		//指定の文字、文字列で始まるかを判定する
		bool starts_with(char c)const noexcept{
			return m_str[0] == c;
		}
		bool starts_with(const char* c)const noexcept{
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
		bool ends_with(char c)const noexcept{
			return m_str[m_str.size() - 1] == c;
		}
		bool ends_with(const char* c)const noexcept{
			//文字数カウント
			int len = 0;
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
	};
}
