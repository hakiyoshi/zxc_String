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
		//�R���X�g���N�^�A�f�X�g���N�^
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

		//�F�X
		unsigned long long length()const noexcept { return stringInfo.length(); }//������̒���
		unsigned long long maxsize()const noexcept { return stringInfo.max_size(); }//�i�[�\�ȍő啶����
		void resize(unsigned int size, char c) { stringInfo.resize(size, c); }//������̒�����ύX����
		void resize(unsigned int size) { stringInfo.resize(size); }
		unsigned int capacity() const noexcept { return stringInfo.capacity(); }//���������Ċm�ۂ����Ɋi�[�ł���ő�̗v�f�����擾����
		void reserve(unsigned int capacity) { stringInfo.reserve(capacity); }//capacity��ύX����
		void shrink_to_fit() { stringInfo.shrink_to_fit(); }//capacity��size�܂ŕύX����
		void clear()noexcept { stringInfo.clear(); }//��������N���A����
		bool empty() const noexcept { return stringInfo.empty(); }//�����񂪋󂩔��肷��

		//begin,end�n
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

		//�v�f�ɃA�N�Z�X
		ControlString str()const noexcept { return stringInfo; }//std��string�ŕ�������擾����
		const char* c_str()const noexcept { return stringInfo.c_str(); }//c����̕�����\���Ŏ擾����

		char at(unsigned int pos)const { return stringInfo[pos]; }
		char at(unsigned int pos) { return stringInfo[pos]; }
		char operator[](unsigned int pos)const { return stringInfo[pos]; }
		char operator[](unsigned int pos) { return stringInfo[pos]; }

		char front()const { return stringInfo.front(); }
		char front() { return stringInfo.front(); }
		char back()const { return stringInfo.back(); }
		char back() { return stringInfo.back(); }

		//�R�s�[
		unsigned long long copy(char* str, unsigned int n, unsigned int pos = 0)const{
			return stringInfo.copy(str, n, pos);
		}

		//�Ō�ɕ����ǉ�
		void push_back(char c) { stringInfo.push_back(c); }

		//�����A������ǉ�
		String& operator+=(const String& str){//������ǉ�
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

		String& operator+=(char c){//�����ǉ�
			stringInfo += c;
			return *this;
		}

		String& append(const String& str){//������ǉ�
			stringInfo.append(str.stringInfo);
			return *this;
		}
		String& append(const ControlString& str) {
			stringInfo.append(str);
			return *this;
		}

		String& append(const String& str, unsigned int pos, unsigned int n = ControlString::npos) {//�ǉ����镶����̊J�n�ʒu�ƕ��������w�肵��
			stringInfo.append(str.stringInfo, pos, n);
			return *this;
		}
		String& append(const ControlString& str, unsigned int pos, unsigned int n = ControlString::npos) {
			stringInfo.append(str, pos, n);
			return *this;
		}

		String& append(const String& str, unsigned int n = ControlString::npos) {//�ǉ����镶����̕��������w�肵�Ēǉ�
			stringInfo.append(str.stringInfo, n);
			return *this;
		}
		String& append(const ControlString& str, unsigned int n = ControlString::npos) {
			stringInfo.append(str, n);
			return *this;
		}

		String& append(const char* str) {//������ǉ�
			stringInfo.append(str);
			return *this;
		}

		String& append(unsigned int n, char str) {//str�̕�����n���A������悤�ɒǉ�
			stringInfo.append(n, str);
			return *this;
		}


		//�����A��������㏑��
		String& assign(const String& str){//��������㏑��
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

		String& assign(const String& str, unsigned int pos, unsigned int n = ControlString::npos) {//�㏑�����镶����̈ʒu�ƕ��������w�肷��
			stringInfo.assign(str.stringInfo, pos, n);
			return *this;
		}
		String& assign(const ControlString& str, unsigned int pos, unsigned int n = ControlString::npos) {
			stringInfo.assign(str, pos, n);
			return *this;
		}

		String& assign(const String& str, unsigned int n = ControlString::npos) {//�㏑�����镶����̕��������w�肷��
			stringInfo.assign(str.stringInfo, n);
			return *this;
		}
		String& assign(const ControlString& str, unsigned int n = ControlString::npos) {
			stringInfo.assign(str, n);
			return *this;
		}

		String& assign(const char* str) {//������㏑��
			stringInfo.assign(str);
			return *this;
		}

		String& assign(unsigned int n, char c) {//c�Ŏw�肵��������n���A���ɂȂ�悤�ɏ㏑������
			stringInfo.assign(n, c);
			return *this;
		}

		//�����A�������}������
		String& insert(unsigned int pos1, const String& str){//�w��ʒu�ɕ������}������
			stringInfo.insert(pos1, str.stringInfo);
			return *this;
		}
		String& insert(unsigned int pos1, const ControlString& str) {
			stringInfo.insert(pos1, str);
			return *this;
		}

		String& insert(unsigned int pos1, const String& str, unsigned int pos2, unsigned int n = ControlString::npos){//�w��ʒu�ɁA�����������}������
			stringInfo.insert(pos1, str.stringInfo, pos2, n);
			return *this;
		}
		String& insert(unsigned int pos1, const ControlString& str, unsigned int pos2, unsigned int n = ControlString::npos) {
			stringInfo.insert(pos1, str, pos2, n);
			return *this;
		}

		String& insert(unsigned int pos, const char* str, unsigned int n){//�w��ʒu�ɁA�����z��̐擪N������}������
			stringInfo.insert(pos, str, n);
			return *this;
		}
		String& insert(unsigned int pos, const char* str){//�w��ʒu�ɕ����z���}������
			stringInfo.insert(pos, str);
			return *this;
		}
		String& insert(unsigned int pos, unsigned int n, char c){//�w��ʒu�ɁAN�̕�����}������
			stringInfo.insert(pos, n, c);
			return *this;
		}

		auto insert(const ControlString::iterator& itr, char c){//�w�肵���C�e���[�^���w���v�f�̑O�ɁA������}������
			return stringInfo.insert(itr, c);
		}
		auto insert(const ControlString::const_iterator& itr, char c) {
			return stringInfo.insert(itr, c);
		}

		auto insert(const ControlString::iterator& itr, unsigned int n, char c) {//�w�肵���C�e���[�^���w���v�f�̑O�ɁAN�̕�����}������
			return stringInfo.insert(itr, n, c);
		}
		auto insert(const ControlString::const_iterator& itr, unsigned int n, char c) {
			return stringInfo.insert(itr, n, c);
		}

		//�v�f���폜
		String& erase(unsigned int pos = 0, unsigned int n = ControlString::npos){//pos�Ԗڂ���n�v�f���폜����B
			stringInfo.erase(pos, n);
			return *this;
		}
		auto erase(const ControlString::const_iterator& itr) { return stringInfo.erase(itr); }//�C�e���[�^p���w���v�f���폜����
		auto erase(const ControlString::const_iterator& first, const ControlString::const_iterator& last) { return stringInfo.erase(first, last); }//�C�e���[�^�͈�[first, last)���폜����

		//�����̈ꕶ�����폜����
		void pop_back() { stringInfo.pop_back(); }

		//������̈ꕔ��u��������
		String& replace(unsigned int pos1, unsigned int n1, const String& str){//�w�肵���ʒu����N�������A������Œu��������
			stringInfo.replace(pos1, n1, str.stringInfo);
			return *this;
		}
		String& replace(unsigned int pos1, unsigned int n1, const ControlString& str) {
			stringInfo.replace(pos1, n1, str);
			return *this;
		}

		String& replace(//�w�肵���ꂩ��N�������A������̈ꕔ�Œu��������
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

		String& replace(unsigned int pos, unsigned int n1, const char* str, unsigned int n2){//�w�肵���ʒu����N�������A�����z��̐擪M�����Œu��������
			stringInfo.replace(pos, n1, str, n2);
			return *this;
		}
		String& replace(unsigned int pos, unsigned int n1, const char* str) {//�w�肵���ʒu����N�������A�����z��Œu��������
			stringInfo.replace(pos, n1, str);
			return *this;
		}
		String& replace(unsigned int pos, unsigned int n1, unsigned int n2, char str) {//�w�肵���ʒu����N�������AM�̕����Œu��������
			stringInfo.replace(pos, n1, n2, str);
			return *this;
		}

		String& replace(const ControlString::iterator& i1, const ControlString::iterator& i2, const String& str){//�w�肵���C�e���[�^�͈͂��A������Œu��������
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

		String& replace(const ControlString::iterator& i1, const ControlString::iterator& i2, const char* str, unsigned int n){//�w�肵���C�e���[�^�͈͂��A�����z��̐擪N�����Œu��������
			stringInfo.replace(i1, i2, str, n);
			return *this;
		}
		String& replace(const ControlString::const_iterator& i1, const ControlString::const_iterator& i2, const char* str, unsigned int n) {
			stringInfo.replace(i1, i2, str, n);
			return *this;
		}

		String& replace(const ControlString::iterator& i1, const ControlString::iterator& i2, const char* str) {//�w�肵���C�e���[�^�͈͂��A�����z��Œu��������
			stringInfo.replace(i1, i2, str);
			return *this;
		}
		String& replace(const ControlString::const_iterator& i1, const ControlString::const_iterator& i2, const char* str) {
			stringInfo.replace(i1, i2, str);
			return *this;
		}

		String& replace(const ControlString::iterator& i1, const ControlString::iterator& i2, unsigned int n, char c) {//�w�肵���C�e���[�^�͈͂��AN�̕����Œu��������
			stringInfo.replace(i1, i2, n, c);
			return *this;
		}
		String& replace(const ControlString::const_iterator& i1, const ControlString::const_iterator& i2, unsigned int n, char c) {
			stringInfo.replace(i1, i2, n, c);
			return *this;
		}

		//�f�[�^�����ւ���
		void swap(String& str)noexcept { stringInfo.swap(str.stringInfo); }

		//���������������
		unsigned long long find(const String& str, unsigned int pos = 0)const noexcept{//pos �ȍ~�ōŏ��� str �ƈ�v����ʒu��Ԃ�
			return stringInfo.find(str.stringInfo, pos);
		}
		unsigned long long find(const ControlString& str, unsigned int pos = 0)const {
			return stringInfo.find(str, pos);
		}

		unsigned long long find(const char* str, unsigned int pos, unsigned int n)const{//pos �ȍ~�ōŏ��� s �ƈ�v����ʒu��Ԃ��Bs �͒��� n �̕�����ւ̃|�C���^�ł���
			return stringInfo.find(str, pos, n);
		}
		unsigned long long find(const char* str, unsigned int pos = 0)const {//NULL �I�[�̕����������
			return stringInfo.find(str, pos);
		}

		unsigned long long find(char c, unsigned int pos = 0)const{//pos �ȍ~�ōŏ��� c �ƈ�v����ʒu��Ԃ�
			return stringInfo.find(c, pos);
		}

		//�Ō�Ɍ����w�蕶�������������
		unsigned long long rfind(const String& str, unsigned int pos = ControlString::npos) const noexcept {//pos �ȑO�ōŌ�� str �ƈ�v����ʒu��Ԃ�
			return stringInfo.rfind(str.stringInfo, pos);
		}
		unsigned long long rfind(const ControlString& str, unsigned int pos = ControlString::npos) const noexcept {
			return stringInfo.rfind(str, pos);
		}

		unsigned long long rfind(const char* str, unsigned int pos, unsigned int n)const{//pos �ȑO�ōŌ�� s �ƈ�v����ʒu��Ԃ��Bs �͒��� n �̕�����ւ̃|�C���^�ł���
			return stringInfo.rfind(str, pos, n);
		}
		unsigned long long rfind(const char* str, unsigned int pos = ControlString::npos)const {//NULL �I�[�̕����������
			return stringInfo.rfind(str, pos);
		}

		unsigned long long rfind(char c, unsigned int pos = ControlString::npos)const{//pos �ȑO�ōŌ�� c �ƈ�v����ʒu��Ԃ�
			return stringInfo.rfind(c, pos);
		}

		//�ŏ��Ɍ����w�蕶������������
		unsigned long long find_first_of(const String& str, unsigned int pos = 0)const noexcept{//pos �ȍ~�ōŏ��� str ���ɑ��݂��镶���̈ʒu��Ԃ�
			return stringInfo.find_first_of(str.stringInfo, pos);
		}
		unsigned long long find_first_of(const ControlString& str, unsigned int pos = 0)const noexcept {
			return stringInfo.find_first_of(str, pos);
		}

		unsigned long long find_first_of(const char* str, unsigned int pos, unsigned int n)const {//pos �ȍ~�ōŏ��� s ���ɑ��݂��镶���̈ʒu��Ԃ��Bs �͒��� n �̕�����ւ̃|�C���^�ł���
			return stringInfo.find_first_of(str, pos, n);
		}
		unsigned long long find_first_of(const char* str, unsigned int pos = 0)const {// NULL �I�[�̕����������
			return stringInfo.find_first_of(str, pos);
		}

		unsigned long long find_first_of(char c, unsigned int pos = 0)const {//pos �ȍ~�ōŏ��� c �ƈ�v���镶���̈ʒu��Ԃ�
			return stringInfo.find_first_of(c, pos);
		}

		//�Ō�Ɍ����w�蕶������������
		unsigned long long find_last_of(const String& str, unsigned int pos = 0)const noexcept {//pos �ȑO�ōŏ��� str ���ɑ��݂��镶���̈ʒu��Ԃ�
			return stringInfo.find_last_of(str.stringInfo, pos);
		}
		unsigned long long find_last_of(const ControlString& str, unsigned int pos = 0)const noexcept {
			return stringInfo.find_last_of(str, pos);
		}

		unsigned long long find_last_of(const char* str, unsigned int pos, unsigned int n)const {//pos �ȑO�ōŏ��� s ���ɑ��݂��镶���̈ʒu��Ԃ��Bs �͒��� n �̕�����ւ̃|�C���^�ł���
			return stringInfo.find_last_of(str, pos, n);
		}
		unsigned long long find_last_of(const char* str, unsigned int pos = 0)const {// NULL �I�[�̕����������
			return stringInfo.find_last_of(str, pos);
		}

		unsigned long long find_last_of(char c, unsigned int pos = 0)const {//pos �ȑO�ōŏ��� c �ƈ�v���镶���̈ʒu��Ԃ�
			return stringInfo.find_last_of(c, pos);
		}

		//�擪����w�蕶����������Ȃ��ʒu����������
		unsigned long long find_first_not_of(const String& str, unsigned int pos = 0)const noexcept {//pos �ȍ~�ōŏ��� str ���ɑ��݂��镶���̈ʒu��Ԃ�
			return stringInfo.find_first_not_of(str.stringInfo, pos);
		}
		unsigned long long find_first_not_of(const ControlString& str, unsigned int pos = 0)const noexcept {
			return stringInfo.find_first_not_of(str, pos);
		}

		unsigned long long find_first_not_of(const char* str, unsigned int pos, unsigned int n)const {//pos �ȍ~�ōŏ��� s ���ɑ��݂��镶���̈ʒu��Ԃ��Bs �͒��� n �̕�����ւ̃|�C���^�ł���
			return stringInfo.find_first_not_of(str, pos, n);
		}
		unsigned long long find_first_not_of(const char* str, unsigned int pos = 0)const {// NULL �I�[�̕����������
			return stringInfo.find_first_not_of(str, pos);
		}

		unsigned long long find_first_not_of(char c, unsigned int pos = 0)const {//pos �ȍ~�ōŏ��� c �ƈ�v���镶���̈ʒu��Ԃ�
			return stringInfo.find_first_not_of(c, pos);
		}

		//��������A�w�蕶����������Ȃ��ʒu����������
		unsigned long long find_last_not_of(const String& str, unsigned int pos = 0)const noexcept {//pos �ȑO�ōŏ��� str ���ɑ��݂��镶���̈ʒu��Ԃ�
			return stringInfo.find_last_not_of(str.stringInfo, pos);
		}
		unsigned long long find_last_not_of(const ControlString& str, unsigned int pos = 0)const noexcept {
			return stringInfo.find_last_not_of(str, pos);
		}

		unsigned long long find_last_not_of(const char* str, unsigned int pos, unsigned int n)const {//pos �ȑO�ōŏ��� s ���ɑ��݂��镶���̈ʒu��Ԃ��Bs �͒��� n �̕�����ւ̃|�C���^�ł���
			return stringInfo.find_last_not_of(str, pos, n);
		}
		unsigned long long find_last_not_of(const char* str, unsigned int pos = 0)const {// NULL �I�[�̕����������
			return stringInfo.find_last_not_of(str, pos);
		}

		unsigned long long find_last_not_of(char c, unsigned int pos = 0)const {//pos �ȑO�ōŏ��� c �ƈ�v���镶���̈ʒu��Ԃ�
			return stringInfo.find_last_not_of(c, pos);
		}

		//������������擾����
		String substr(unsigned int pos = 0, unsigned int n = std::string::npos)const{
			return stringInfo.substr(pos, n);
		}

		//���̕�����Ƃ̔�r���s��
		int compara(const String& str)const noexcept{
			return stringInfo.compare(str.stringInfo);
		}
		int compara(const ControlString& str)const noexcept {
			return stringInfo.compare(str);
		}

		//�w��̕����A������Ŏn�܂邩�𔻒肷��
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

		//�w��̕�����ŏI��邩�𔻒肷��
		bool ends_with(char c)const noexcept{
			return stringInfo[stringInfo.size() - 1] == c;
		}
		bool ends_with(const char* c)const noexcept{
			//�������J�E���g
			int len = 0;
			for (len = 0; c[len] != '\0';)
				len++;

			//���������傫���ꍇ
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
