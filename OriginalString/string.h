#pragma once
#include <string>

namespace Ghl
{
	class String
	{
	private:
		using ControlString = std::string;

	private:
		ControlString stringInfo;

	public:
		//コンストラクタ、デストラクタ
		String() = default;
		String(const String& str) = default;
		String(String&& str) noexcept = default;
		String(ControlString str) : stringInfo(std::move(str)){}
		explicit String(const char* str) : stringInfo(str){}
		String(const char* str, size_t sizeType) : stringInfo(str, sizeType){}
		String(size_t sizeType, const char* str) : stringInfo(str, sizeType) {}
		explicit String(nullptr_t) = delete;
		~String() = default;

		//operator=
		String& operator=(const String&) = default;
		String& operator=(String&&) = default;
		String& operator=(const char* str){
			stringInfo = str;
			return *this;
		}
		String& operator=(const ControlString& str){
			stringInfo = str;
			return *this;
		}
		String& operator=(ControlString&& str){
			stringInfo = str;
			return *this;
		}

		//色々
		unsigned long long length()const noexcept { return stringInfo.length(); }//文字列の長さ
		unsigned long long maxsize()const noexcept { return stringInfo.max_size(); }//格納可能な最大文字列長
		void resize(unsigned int size, char c) { stringInfo.resize(size, c); }//文字列の長さを変更する
		void resize(unsigned int size) { stringInfo.resize(size); }
		unsigned int capacity() const noexcept { return stringInfo.capacity(); }//メモリを再確保せずに格納できる最大の要素数を取得する
		void reserve(unsigned int capacity) { stringInfo.reserve(capacity); }//capacityを変更する
		void shrink_to_fit() { stringInfo.shrink_to_fit(); }//capacityをsizeまで変更する
		void clear()noexcept { stringInfo.clear(); }//文字列をクリアする
		bool empty() const noexcept { return stringInfo.empty(); }//文字列が空か判定する

		//begin,end系
		auto begin() { return stringInfo.begin(); }
		auto begin()const { return stringInfo.begin(); }
		auto end() { return stringInfo.end(); }
		auto end()const { return stringInfo.end(); }
		auto cbegin() { return stringInfo.cbegin(); }
		auto cbegin()const { return stringInfo.cbegin(); }
		auto cend() { return stringInfo.cend(); }
		auto cend()const { return stringInfo.cend(); }
		auto rbegin() { return stringInfo.rbegin(); }
		auto rbegin()const { return stringInfo.rbegin(); }
		auto rend() { return stringInfo.rend(); }
		auto rend()const { return stringInfo.rend(); }
		auto crbegin() { return stringInfo.crbegin(); }
		auto crbegin()const { return stringInfo.crbegin(); }
		auto crend() { return stringInfo.crend(); }
		auto crend()const { return stringInfo.crend(); }

		//要素にアクセス
		ControlString str()const noexcept { return stringInfo; }//stdのstringで文字列を取得する
		const char* c_str()const noexcept { return stringInfo.c_str(); }//c言語の文字列表現で取得する

		char at(unsigned int pos)const { return stringInfo[pos]; }
		char at(unsigned int pos) { return stringInfo[pos]; }
		char operator[](unsigned int pos)const { return stringInfo[pos]; }
		char operator[](unsigned int pos) { return stringInfo[pos]; }

		char front()const { return stringInfo.front(); }
		char front() { return stringInfo.front(); }
		char back()const { return stringInfo.back(); }
		char back() { return stringInfo.back(); }

		//コピー
		unsigned long long copy(char* str, unsigned int n, unsigned int pos = 0)const{
			return stringInfo.copy(str, n, pos);
		}

		//最後に文字追加
		void push_back(char c) { stringInfo.push_back(c); }

		//文字、文字列追加
		String& operator+=(const String& str){//文字列追加
			stringInfo += str.stringInfo;
			return *this;
		}
		String& operator+=(const ControlString& str) {
			stringInfo += str;
			return *this;
		}
		String& operator+=(const char* str){
			stringInfo += str;
			return *this;
		}

		String& operator+=(char c){//文字追加
			stringInfo += c;
			return *this;
		}

		String& append(const String& str){//文字列追加
			stringInfo.append(str.stringInfo);
			return *this;
		}
		String& append(const ControlString& str) {
			stringInfo.append(str);
			return *this;
		}

		String& append(const String& str, unsigned int pos, unsigned int n = ControlString::npos) {//追加する文字列の開始位置と文字数を指定して
			stringInfo.append(str.stringInfo, pos, n);
			return *this;
		}
		String& append(const ControlString& str, unsigned int pos, unsigned int n = ControlString::npos) {
			stringInfo.append(str, pos, n);
			return *this;
		}

		String& append(const String& str, unsigned int n = ControlString::npos) {//追加する文字列の文字数を指定して追加
			stringInfo.append(str.stringInfo, n);
			return *this;
		}
		String& append(const ControlString& str, unsigned int n = ControlString::npos) {
			stringInfo.append(str, n);
			return *this;
		}

		String& append(const char* str) {//文字列追加
			stringInfo.append(str);
			return *this;
		}

		String& append(unsigned int n, char str) {//strの文字をn個分連続するように追加
			stringInfo.append(n, str);
			return *this;
		}


		//文字、文字列を上書き
		String& assign(const String& str){//文字列を上書き
			stringInfo.assign(str.stringInfo);
			return *this;
		}
		String& assign(String&& str)noexcept {
			stringInfo.assign(str.stringInfo);
			return *this;
		}
		String& assign(const ControlString& str) {
			stringInfo.assign(str);
			return *this;
		}

		String& assign(const String& str, unsigned int pos, unsigned int n = ControlString::npos) {//上書きする文字列の位置と文字数を指定する
			stringInfo.assign(str.stringInfo, pos, n);
			return *this;
		}
		String& assign(const ControlString& str, unsigned int pos, unsigned int n = ControlString::npos) {
			stringInfo.assign(str, pos, n);
			return *this;
		}

		String& assign(const String& str, unsigned int n = ControlString::npos) {//上書きする文字列の文字数を指定する
			stringInfo.assign(str.stringInfo, n);
			return *this;
		}
		String& assign(const ControlString& str, unsigned int n = ControlString::npos) {
			stringInfo.assign(str, n);
			return *this;
		}

		String& assign(const char* str) {//文字列上書き
			stringInfo.assign(str);
			return *this;
		}

		String& assign(unsigned int n, char c) {//cで指定した文字をn個分連続になるように上書きする
			stringInfo.assign(n, c);
			return *this;
		}

		//文字、文字列を挿入する
		String& insert(unsigned int pos1, const String& str){//指定位置に文字列を挿入する
			stringInfo.insert(pos1, str.stringInfo);
			return *this;
		}
		String& insert(unsigned int pos1, const ControlString& str) {
			stringInfo.insert(pos1, str);
			return *this;
		}

		String& insert(unsigned int pos1, const String& str, unsigned int pos2, unsigned int n = ControlString::npos){//指定位置に、部分文字列を挿入する
			stringInfo.insert(pos1, str.stringInfo, pos2, n);
			return *this;
		}
		String& insert(unsigned int pos1, const ControlString& str, unsigned int pos2, unsigned int n = ControlString::npos) {
			stringInfo.insert(pos1, str, pos2, n);
			return *this;
		}

		String& insert(unsigned int pos, const char* str, unsigned int n){//指定位置に、文字配列の先頭N文字を挿入する
			stringInfo.insert(pos, str, n);
			return *this;
		}
		String& insert(unsigned int pos, const char* str){//指定位置に文字配列を挿入する
			stringInfo.insert(pos, str);
			return *this;
		}
		String& insert(unsigned int pos, unsigned int n, char c){//指定位置に、N個の文字を挿入する
			stringInfo.insert(pos, n, c);
			return *this;
		}

		auto insert(const ControlString::iterator& itr, char c){//指定したイテレータが指す要素の前に、文字を挿入する
			return stringInfo.insert(itr, c);
		}
		auto insert(const ControlString::const_iterator& itr, char c) {
			return stringInfo.insert(itr, c);
		}

		auto insert(const ControlString::iterator& itr, unsigned int n, char c) {//指定したイテレータが指す要素の前に、N個の文字を挿入する
			return stringInfo.insert(itr, n, c);
		}
		auto insert(const ControlString::const_iterator& itr, unsigned int n, char c) {
			return stringInfo.insert(itr, n, c);
		}

		//要素を削除
		String& erase(unsigned int pos = 0, unsigned int n = ControlString::npos){//pos番目からn要素を削除する。
			stringInfo.erase(pos, n);
			return *this;
		}
		auto erase(const ControlString::const_iterator& itr) { return stringInfo.erase(itr); }//イテレータpが指す要素を削除する
		auto erase(const ControlString::const_iterator& first, const ControlString::const_iterator& last) { return stringInfo.erase(first, last); }//イテレータ範囲[first, last)を削除する

		//末尾の一文字を削除する
		void pop_back() { stringInfo.pop_back(); }

		//文字列の一部を置き換える
		String& replace(unsigned int pos1, unsigned int n1, const String& str){//指定した位置からN文字を、文字列で置き換える
			stringInfo.replace(pos1, n1, str.stringInfo);
			return *this;
		}
		String& replace(unsigned int pos1, unsigned int n1, const ControlString& str) {
			stringInfo.replace(pos1, n1, str);
			return *this;
		}

		String& replace(//指定した一からN文字を、文字列の一部で置き換える
			unsigned int pos1, unsigned int n1, const String& str,
			unsigned int pos2, unsigned n2 = ControlString::npos){
			stringInfo.replace(pos1, n1, str.stringInfo, pos2, n2);
			return *this;
		}
		String& replace(
			unsigned int pos1, unsigned int n1, const ControlString& str,
			unsigned int pos2, unsigned n2 = ControlString::npos) {
			stringInfo.replace(pos1, n1, str, pos2, n2);
			return *this;
		}

		String& replace(unsigned int pos, unsigned int n1, const char* str, unsigned int n2){//指定した位置からN文字を、文字配列の先頭M文字で置き換える
			stringInfo.replace(pos, n1, str, n2);
			return *this;
		}
		String& replace(unsigned int pos, unsigned int n1, const char* str) {//指定した位置からN文字を、文字配列で置き換える
			stringInfo.replace(pos, n1, str);
			return *this;
		}
		String& replace(unsigned int pos, unsigned int n1, unsigned int n2, char str) {//指定した位置からN文字を、M個の文字で置き換える
			stringInfo.replace(pos, n1, n2, str);
			return *this;
		}

		String& replace(const ControlString::iterator& i1, const ControlString::iterator& i2, const String& str){//指定したイテレータ範囲を、文字列で置き換える
			stringInfo.replace(i1, i2, str.stringInfo);
			return *this;
		}
		String& replace(const ControlString::const_iterator& i1, const ControlString::const_iterator& i2, const String& str) {
			stringInfo.replace(i1, i2, str.stringInfo);
			return *this;
		}
		String& replace(const ControlString::iterator& i1, const ControlString::iterator& i2, const ControlString& str) {
			stringInfo.replace(i1, i2, str);
			return *this;
		}
		String& replace(const ControlString::const_iterator& i1, const ControlString::const_iterator& i2, const ControlString& str) {
			stringInfo.replace(i1, i2, str);
			return *this;
		}

		String& replace(const ControlString::iterator& i1, const ControlString::iterator& i2, const char* str, unsigned int n){//指定したイテレータ範囲を、文字配列の先頭N文字で置き換える
			stringInfo.replace(i1, i2, str, n);
			return *this;
		}
		String& replace(const ControlString::const_iterator& i1, const ControlString::const_iterator& i2, const char* str, unsigned int n) {
			stringInfo.replace(i1, i2, str, n);
			return *this;
		}

		String& replace(const ControlString::iterator& i1, const ControlString::iterator& i2, const char* str) {//指定したイテレータ範囲を、文字配列で置き換える
			stringInfo.replace(i1, i2, str);
			return *this;
		}
		String& replace(const ControlString::const_iterator& i1, const ControlString::const_iterator& i2, const char* str) {
			stringInfo.replace(i1, i2, str);
			return *this;
		}

		String& replace(const ControlString::iterator& i1, const ControlString::iterator& i2, unsigned int n, char c) {//指定したイテレータ範囲を、N個の文字で置き換える
			stringInfo.replace(i1, i2, n, c);
			return *this;
		}
		String& replace(const ControlString::const_iterator& i1, const ControlString::const_iterator& i2, unsigned int n, char c) {
			stringInfo.replace(i1, i2, n, c);
			return *this;
		}

		//データを入れ替える
		void swap(String& str)noexcept { stringInfo.swap(str.stringInfo); }

		//文字列を検索する
		unsigned long long find(const String& str, unsigned int pos = 0)const noexcept{//pos 以降で最初に str と一致する位置を返す
			return stringInfo.find(str.stringInfo, pos);
		}
		unsigned long long find(const ControlString& str, unsigned int pos = 0)const {
			return stringInfo.find(str, pos);
		}

		unsigned long long find(const char* str, unsigned int pos, unsigned int n)const{//pos 以降で最初に s と一致する位置を返す。s は長さ n の文字列へのポインタである
			return stringInfo.find(str, pos, n);
		}
		unsigned long long find(const char* str, unsigned int pos = 0)const {//NULL 終端の文字列を扱う
			return stringInfo.find(str, pos);
		}

		unsigned long long find(char c, unsigned int pos = 0)const{//pos 以降で最初に c と一致する位置を返す
			return stringInfo.find(c, pos);
		}

		//最後に現れる指定文字列を検索する
		unsigned long long rfind(const String& str, unsigned int pos = ControlString::npos) const noexcept {//pos 以前で最後に str と一致する位置を返す
			return stringInfo.rfind(str.stringInfo, pos);
		}
		unsigned long long rfind(const ControlString& str, unsigned int pos = ControlString::npos) const noexcept {
			return stringInfo.rfind(str, pos);
		}

		unsigned long long rfind(const char* str, unsigned int pos, unsigned int n)const{//pos 以前で最後に s と一致する位置を返す。s は長さ n の文字列へのポインタである
			return stringInfo.rfind(str, pos, n);
		}
		unsigned long long rfind(const char* str, unsigned int pos = ControlString::npos)const {//NULL 終端の文字列を扱う
			return stringInfo.rfind(str, pos);
		}

		unsigned long long rfind(char c, unsigned int pos = ControlString::npos)const{//pos 以前で最後に c と一致する位置を返す
			return stringInfo.rfind(c, pos);
		}

		//最初に現れる指定文字を検索する
		unsigned long long find_first_of(const String& str, unsigned int pos = 0)const noexcept{//pos 以降で最初に str 内に存在する文字の位置を返す
			return stringInfo.find_first_of(str.stringInfo, pos);
		}
		unsigned long long find_first_of(const ControlString& str, unsigned int pos = 0)const noexcept {
			return stringInfo.find_first_of(str, pos);
		}

		unsigned long long find_first_of(const char* str, unsigned int pos, unsigned int n)const {//pos 以降で最初に s 内に存在する文字の位置を返す。s は長さ n の文字列へのポインタである
			return stringInfo.find_first_of(str, pos, n);
		}
		unsigned long long find_first_of(const char* str, unsigned int pos = 0)const {// NULL 終端の文字列を扱う
			return stringInfo.find_first_of(str, pos);
		}

		unsigned long long find_first_of(char c, unsigned int pos = 0)const {//pos 以降で最初に c と一致する文字の位置を返す
			return stringInfo.find_first_of(c, pos);
		}

		//最後に現れる指定文字を検索する
		unsigned long long find_last_of(const String& str, unsigned int pos = 0)const noexcept {//pos 以前で最初に str 内に存在する文字の位置を返す
			return stringInfo.find_last_of(str.stringInfo, pos);
		}
		unsigned long long find_last_of(const ControlString& str, unsigned int pos = 0)const noexcept {
			return stringInfo.find_last_of(str, pos);
		}

		unsigned long long find_last_of(const char* str, unsigned int pos, unsigned int n)const {//pos 以前で最初に s 内に存在する文字の位置を返す。s は長さ n の文字列へのポインタである
			return stringInfo.find_last_of(str, pos, n);
		}
		unsigned long long find_last_of(const char* str, unsigned int pos = 0)const {// NULL 終端の文字列を扱う
			return stringInfo.find_last_of(str, pos);
		}

		unsigned long long find_last_of(char c, unsigned int pos = 0)const {//pos 以前で最初に c と一致する文字の位置を返す
			return stringInfo.find_last_of(c, pos);
		}

		//先頭から指定文字が見つからない位置を検索する
		unsigned long long find_first_not_of(const String& str, unsigned int pos = 0)const noexcept {//pos 以降で最初に str 内に存在する文字の位置を返す
			return stringInfo.find_first_not_of(str.stringInfo, pos);
		}
		unsigned long long find_first_not_of(const ControlString& str, unsigned int pos = 0)const noexcept {
			return stringInfo.find_first_not_of(str, pos);
		}

		unsigned long long find_first_not_of(const char* str, unsigned int pos, unsigned int n)const {//pos 以降で最初に s 内に存在する文字の位置を返す。s は長さ n の文字列へのポインタである
			return stringInfo.find_first_not_of(str, pos, n);
		}
		unsigned long long find_first_not_of(const char* str, unsigned int pos = 0)const {// NULL 終端の文字列を扱う
			return stringInfo.find_first_not_of(str, pos);
		}

		unsigned long long find_first_not_of(char c, unsigned int pos = 0)const {//pos 以降で最初に c と一致する文字の位置を返す
			return stringInfo.find_first_not_of(c, pos);
		}

		//末尾から、指定文字が見つからない位置を検索する
		unsigned long long find_last_not_of(const String& str, unsigned int pos = 0)const noexcept {//pos 以前で最初に str 内に存在する文字の位置を返す
			return stringInfo.find_last_not_of(str.stringInfo, pos);
		}
		unsigned long long find_last_not_of(const ControlString& str, unsigned int pos = 0)const noexcept {
			return stringInfo.find_last_not_of(str, pos);
		}

		unsigned long long find_last_not_of(const char* str, unsigned int pos, unsigned int n)const {//pos 以前で最初に s 内に存在する文字の位置を返す。s は長さ n の文字列へのポインタである
			return stringInfo.find_last_not_of(str, pos, n);
		}
		unsigned long long find_last_not_of(const char* str, unsigned int pos = 0)const {// NULL 終端の文字列を扱う
			return stringInfo.find_last_not_of(str, pos);
		}

		unsigned long long find_last_not_of(char c, unsigned int pos = 0)const {//pos 以前で最初に c と一致する文字の位置を返す
			return stringInfo.find_last_not_of(c, pos);
		}

		//部分文字列を取得する
		String substr(unsigned int pos = 0, unsigned int n = std::string::npos)const{
			return stringInfo.substr(pos, n);
		}

		//他の文字列との比較を行う
		int compara(const String& str)const noexcept{
			return stringInfo.compare(str.stringInfo);
		}
		int compara(const ControlString& str)const noexcept {
			return stringInfo.compare(str);
		}

		//指定の文字、文字列で始まるかを判定する
		bool starts_with(char c)const noexcept{
			return stringInfo[0] == c;
		}
		bool starts_with(const char* c)const noexcept{
			for (int i = 0; i < stringInfo.size(); ++i)
			{
				if (c[i] == '\0')
					return true;

				if (c[i] != stringInfo[i])
					return false;
			}

			return false;
		}

		//指定の文字列で終わるかを判定する
		bool ends_with(char c)const noexcept{
			return stringInfo[stringInfo.size() - 1] == c;
		}
		bool ends_with(const char* c)const noexcept{
			//文字数カウント
			int len = 0;
			for (len = 0; c[len] != '\0';)
				len++;

			//文字数が大きい場合
			if (len >= stringInfo.size())
				return false;

			for (int i = stringInfo.size() - 1; i >= 0; --i)
			{
				if (len - 1 < 0)
					return true;

				if (c[len - 1] != stringInfo[i])
					return false;

				len--;
			}

			return false;
		}
	};
}
