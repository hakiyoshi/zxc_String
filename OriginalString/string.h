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
		//�R���X�g���N�^�A�f�X�g���N�^
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

		//�F�X
		unsigned int length()const noexcept { return m_str.length(); }//������̒���
		unsigned int maxsize()const noexcept { return m_str.max_size(); }//�i�[�\�ȍő啶����
		void resize(unsigned int size, char c) { m_str.resize(size, c); }//������̒�����ύX����
		void resize(unsigned int size) { m_str.resize(size); }
		unsigned int capacity() const noexcept { return m_str.capacity(); }//���������Ċm�ۂ����Ɋi�[�ł���ő�̗v�f�����擾����
		void reserve(unsigned int capacity) { m_str.reserve(capacity); }//capacity��ύX����
		void shrink_to_fit() { m_str.shrink_to_fit(); }//capacity��size�܂ŕύX����
		void clear()noexcept { m_str.clear(); }//��������N���A����
		bool empty()noexcept { return m_str.empty(); }//�����񂪋󂩔��肷��

		//begin,end�n
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

		//�v�f�ɃA�N�Z�X
		control_string str()const noexcept { return m_str; }//std��string�ŕ�������擾����
		const char* c_str()const noexcept { return m_str.c_str(); }//c����̕�����\���Ŏ擾����

		char at(unsigned int pos)const { return m_str[pos]; }
		char at(unsigned int pos) { return m_str[pos]; }
		char operator[](unsigned int pos)const { return m_str[pos]; }
		char operator[](unsigned int pos) { return m_str[pos]; }

		char front()const { return m_str.front(); }
		char front() { return m_str.front(); }
		char back()const { return m_str.back(); }
		char back() { return m_str.back(); }

		//�R�s�[
		unsigned int copy(char* str, unsigned int n, unsigned int pos = 0)const{
			return m_str.copy(str, n, pos);
		}

		//�Ō�ɕ����ǉ�
		void push_back(char c) { m_str.push_back(c); }

		//�����A������ǉ�
		string& operator+=(const string& str){//������ǉ�
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

		string& operator+=(char c){//�����ǉ�
			m_str += c;
			return *this;
		}

		string& append(const string& str){//������ǉ�
			m_str.append(str.m_str);
			return *this;
		}
		string& append(const control_string& str) {
			m_str.append(str);
			return *this;
		}

		string& append(const string& str, unsigned int pos, unsigned int n = control_string::npos) {//�ǉ����镶����̊J�n�ʒu�ƕ��������w�肵��
			m_str.append(str.m_str, pos, n);
			return *this;
		}
		string& append(const control_string& str, unsigned int pos, unsigned int n = control_string::npos) {
			m_str.append(str, pos, n);
			return *this;
		}

		string& append(const string& str, unsigned int n = control_string::npos) {//�ǉ����镶����̕��������w�肵�Ēǉ�
			m_str.append(str.m_str, n);
			return *this;
		}
		string& append(const control_string& str, unsigned int n = control_string::npos) {
			m_str.append(str, n);
			return *this;
		}

		string& append(const char* str) {//������ǉ�
			m_str.append(str);
			return *this;
		}

		string& append(unsigned int n, char str) {//str�̕�����n���A������悤�ɒǉ�
			m_str.append(n, str);
			return *this;
		}


		//�����A��������㏑��
		string& assign(const string& str){//��������㏑��
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

		string& assign(const string& str, unsigned int pos, unsigned int n = control_string::npos) {//�㏑�����镶����̈ʒu�ƕ��������w�肷��
			m_str.assign(str.m_str, pos, n);
			return *this;
		}
		string& assign(const control_string& str, unsigned int pos, unsigned int n = control_string::npos) {
			m_str.assign(str, pos, n);
			return *this;
		}

		string& assign(const string& str, unsigned int n = control_string::npos) {//�㏑�����镶����̕��������w�肷��
			m_str.assign(str.m_str, n);
			return *this;
		}
		string& assign(const control_string& str, unsigned int n = control_string::npos) {
			m_str.assign(str, n);
			return *this;
		}

		string& assign(const char* str) {//������㏑��
			m_str.assign(str);
			return *this;
		}

		string& assign(unsigned int n, char c) {//c�Ŏw�肵��������n���A���ɂȂ�悤�ɏ㏑������
			m_str.assign(n, c);
			return *this;
		}

		//�����A�������}������
		string& insert(unsigned int pos1, const string& str){//�w��ʒu�ɕ������}������
			m_str.insert(pos1, str.m_str);
			return *this;
		}
		string& insert(unsigned int pos1, const control_string& str) {
			m_str.insert(pos1, str);
			return *this;
		}

		string& insert(unsigned int pos1, const string& str, unsigned int pos2, unsigned int n = control_string::npos){//�w��ʒu�ɁA�����������}������
			m_str.insert(pos1, str.m_str, pos2, n);
			return *this;
		}
		string& insert(unsigned int pos1, const control_string& str, unsigned int pos2, unsigned int n = control_string::npos) {
			m_str.insert(pos1, str, pos2, n);
			return *this;
		}

		string& insert(unsigned int pos, const char* str, unsigned int n)//�w��ʒu�ɁA�����z��̐擪N������}������
		{
			m_str.insert(pos, str, n);
			return *this;
		}
		string& insert(unsigned int pos, const char* str)//�w��ʒu�ɕ����z���}������
		{
			m_str.insert(pos, str);
			return *this;
		}
		string& insert(unsigned int pos, unsigned int n, char c){//�w��ʒu�ɁAN�̕�����}������
			m_str.insert(pos, n, c);
			return *this;
		}

		auto insert(control_string::iterator itr, char c){//�w�肵���C�e���[�^���w���v�f�̑O�ɁA������}������
			return m_str.insert(itr, c);
		}
		auto insert(control_string::const_iterator itr, char c) {
			return m_str.insert(itr, c);
		}

		auto insert(control_string::iterator itr, unsigned int n, char c) {//�w�肵���C�e���[�^���w���v�f�̑O�ɁAN�̕�����}������
			return m_str.insert(itr, n, c);
		}
		auto insert(control_string::const_iterator itr, unsigned int n, char c) {
			return m_str.insert(itr, n, c);
		}

		//�v�f���폜
		string& erase(unsigned int pos = 0, unsigned int n = control_string::npos){//pos�Ԗڂ���n�v�f���폜����B
			m_str.erase(pos, n);
			return *this;
		}
		auto erase(control_string::const_iterator itr) { return m_str.erase(itr); }//�C�e���[�^p���w���v�f���폜����
		auto erase(control_string::const_iterator first, control_string::const_iterator last) { return m_str.erase(first, last); }//�C�e���[�^�͈�[first, last)���폜����

		//�����̈ꕶ�����폜����
		void pop_back() { m_str.pop_back(); }

		//������̈ꕔ��u��������
		string& replace(unsigned int pos1, unsigned int n1, const string& str){//�w�肵���ʒu����N�������A������Œu��������
			m_str.replace(pos1, n1, str.m_str);
			return *this;
		}
		string& replace(unsigned int pos1, unsigned int n1, const control_string& str) {
			m_str.replace(pos1, n1, str);
			return *this;
		}

		string& replace(//�w�肵���ꂩ��N�������A������̈ꕔ�Œu��������
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

		string& replace(unsigned int pos, unsigned int n1, const char* str, unsigned int n2){//�w�肵���ʒu����N�������A�����z��̐擪M�����Œu��������
			m_str.replace(pos, n1, str, n2);
			return *this;
		}
		string& replace(unsigned int pos, unsigned int n1, const char* str) {//�w�肵���ʒu����N�������A�����z��Œu��������
			m_str.replace(pos, n1, str);
			return *this;
		}
		string& replace(unsigned int pos, unsigned int n1, unsigned int n2, char str) {//�w�肵���ʒu����N�������AM�̕����Œu��������
			m_str.replace(pos, n1, n2, str);
			return *this;
		}

		string& replace(control_string::iterator i1, control_string::iterator i2, const string& str){//�w�肵���C�e���[�^�͈͂��A������Œu��������
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

		string& replace(control_string::iterator i1, control_string::iterator i2, const char* str, unsigned int n){//�w�肵���C�e���[�^�͈͂��A�����z��̐擪N�����Œu��������
			m_str.replace(i1, i2, str, n);
			return *this;
		}
		string& replace(control_string::const_iterator i1, control_string::const_iterator i2, const char* str, unsigned int n) {
			m_str.replace(i1, i2, str, n);
			return *this;
		}

		string& replace(control_string::iterator i1, control_string::iterator i2, const char* str) {//�w�肵���C�e���[�^�͈͂��A�����z��Œu��������
			m_str.replace(i1, i2, str);
			return *this;
		}
		string& replace(control_string::const_iterator i1, control_string::const_iterator i2, const char* str) {
			m_str.replace(i1, i2, str);
			return *this;
		}

		string& replace(control_string::iterator i1, control_string::iterator i2, unsigned int n, char c) {//�w�肵���C�e���[�^�͈͂��AN�̕����Œu��������
			m_str.replace(i1, i2, n, c);
			return *this;
		}
		string& replace(control_string::const_iterator i1, control_string::const_iterator i2, unsigned int n, char c) {
			m_str.replace(i1, i2, n, c);
			return *this;
		}

		//�f�[�^�����ւ���
		void swap(string& str)noexcept { m_str.swap(str.m_str); }

		//���������������
		unsigned int find(const string& str, unsigned int pos = 0)const noexcept{//pos �ȍ~�ōŏ��� str �ƈ�v����ʒu��Ԃ�
			return m_str.find(str.m_str, pos);
		}
		unsigned int find(const control_string& str, unsigned int pos = 0)const {
			return m_str.find(str, pos);
		}

		unsigned int find(const char* str, unsigned int pos, unsigned int n)const{//pos �ȍ~�ōŏ��� s �ƈ�v����ʒu��Ԃ��Bs �͒��� n �̕�����ւ̃|�C���^�ł���
			return m_str.find(str, pos, n);
		}
		unsigned int find(const char* str, unsigned int pos = 0)const {//NULL �I�[�̕����������
			return m_str.find(str, pos);
		}

		unsigned int find(char c, unsigned int pos = 0)const{//pos �ȍ~�ōŏ��� c �ƈ�v����ʒu��Ԃ�
			return m_str.find(c, pos);
		}

		//�Ō�Ɍ����w�蕶�������������
		unsigned int rfind(const string str, unsigned int pos = control_string::npos)noexcept {//pos �ȑO�ōŌ�� str �ƈ�v����ʒu��Ԃ�
			return m_str.rfind(str.m_str, pos);
		}
		unsigned int rfind(const control_string str, unsigned int pos = control_string::npos)noexcept {
			return m_str.rfind(str, pos);
		}

		unsigned int rfind(const char* str, unsigned int pos, unsigned int n)const{//pos �ȑO�ōŌ�� s �ƈ�v����ʒu��Ԃ��Bs �͒��� n �̕�����ւ̃|�C���^�ł���
			return m_str.rfind(str, pos, n);
		}
		unsigned int rfind(const char* str, unsigned int pos = control_string::npos)const {//NULL �I�[�̕����������
			return m_str.rfind(str, pos);
		}

		unsigned int rfind(char c, unsigned int pos = control_string::npos)const{//pos �ȑO�ōŌ�� c �ƈ�v����ʒu��Ԃ�
			return m_str.rfind(c, pos);
		}

		//�ŏ��Ɍ����w�蕶������������
		unsigned int find_first_of(const string& str, unsigned int pos = 0)const noexcept{//pos �ȍ~�ōŏ��� str ���ɑ��݂��镶���̈ʒu��Ԃ�
			return m_str.find_first_of(str.m_str, pos);
		}
		unsigned int find_first_of(const control_string& str, unsigned int pos = 0)const noexcept {
			return m_str.find_first_of(str, pos);
		}

		unsigned int find_first_of(const char* str, unsigned int pos, unsigned int n)const {//pos �ȍ~�ōŏ��� s ���ɑ��݂��镶���̈ʒu��Ԃ��Bs �͒��� n �̕�����ւ̃|�C���^�ł���
			return m_str.find_first_of(str, pos, n);
		}
		unsigned int find_first_of(const char* str, unsigned int pos = 0)const {// NULL �I�[�̕����������
			return m_str.find_first_of(str, pos);
		}

		unsigned int find_first_of(char c, unsigned int pos = 0)const {//pos �ȍ~�ōŏ��� c �ƈ�v���镶���̈ʒu��Ԃ�
			return m_str.find_first_of(c, pos);
		}

		//�Ō�Ɍ����w�蕶������������
		unsigned int find_last_of(const string& str, unsigned int pos = 0)const noexcept {//pos �ȑO�ōŏ��� str ���ɑ��݂��镶���̈ʒu��Ԃ�
			return m_str.find_last_of(str.m_str, pos);
		}
		unsigned int find_last_of(const control_string& str, unsigned int pos = 0)const noexcept {
			return m_str.find_last_of(str, pos);
		}

		unsigned int find_last_of(const char* str, unsigned int pos, unsigned int n)const {//pos �ȑO�ōŏ��� s ���ɑ��݂��镶���̈ʒu��Ԃ��Bs �͒��� n �̕�����ւ̃|�C���^�ł���
			return m_str.find_last_of(str, pos, n);
		}
		unsigned int find_last_of(const char* str, unsigned int pos = 0)const {// NULL �I�[�̕����������
			return m_str.find_last_of(str, pos);
		}

		unsigned int find_last_of(char c, unsigned int pos = 0)const {//pos �ȑO�ōŏ��� c �ƈ�v���镶���̈ʒu��Ԃ�
			return m_str.find_last_of(c, pos);
		}

		//�擪����w�蕶����������Ȃ��ʒu����������
		unsigned int find_first_not_of(const string& str, unsigned int pos = 0)const noexcept {//pos �ȍ~�ōŏ��� str ���ɑ��݂��镶���̈ʒu��Ԃ�
			return m_str.find_first_not_of(str.m_str, pos);
		}
		unsigned int find_first_not_of(const control_string& str, unsigned int pos = 0)const noexcept {
			return m_str.find_first_not_of(str, pos);
		}

		unsigned int find_first_not_of(const char* str, unsigned int pos, unsigned int n)const {//pos �ȍ~�ōŏ��� s ���ɑ��݂��镶���̈ʒu��Ԃ��Bs �͒��� n �̕�����ւ̃|�C���^�ł���
			return m_str.find_first_not_of(str, pos, n);
		}
		unsigned int find_first_not_of(const char* str, unsigned int pos = 0)const {// NULL �I�[�̕����������
			return m_str.find_first_not_of(str, pos);
		}

		unsigned int find_first_not_of(char c, unsigned int pos = 0)const {//pos �ȍ~�ōŏ��� c �ƈ�v���镶���̈ʒu��Ԃ�
			return m_str.find_first_not_of(c, pos);
		}

		//��������A�w�蕶����������Ȃ��ʒu����������
		unsigned int find_last_not_of(const string& str, unsigned int pos = 0)const noexcept {//pos �ȑO�ōŏ��� str ���ɑ��݂��镶���̈ʒu��Ԃ�
			return m_str.find_last_not_of(str.m_str, pos);
		}
		unsigned int find_last_not_of(const control_string& str, unsigned int pos = 0)const noexcept {
			return m_str.find_last_not_of(str, pos);
		}

		unsigned int find_last_not_of(const char* str, unsigned int pos, unsigned int n)const {//pos �ȑO�ōŏ��� s ���ɑ��݂��镶���̈ʒu��Ԃ��Bs �͒��� n �̕�����ւ̃|�C���^�ł���
			return m_str.find_last_not_of(str, pos, n);
		}
		unsigned int find_last_not_of(const char* str, unsigned int pos = 0)const {// NULL �I�[�̕����������
			return m_str.find_last_not_of(str, pos);
		}

		unsigned int find_last_not_of(char c, unsigned int pos = 0)const {//pos �ȑO�ōŏ��� c �ƈ�v���镶���̈ʒu��Ԃ�
			return m_str.find_last_not_of(c, pos);
		}

		//������������擾����
		string substr(unsigned int pos = 0, unsigned int n = std::string::npos)const{
			return m_str.substr(pos, n);
		}

		//���̕�����Ƃ̔�r���s��
		int compara(const string& str)const noexcept{
			return m_str.compare(str.m_str);
		}
		int compara(const control_string& str)const noexcept {
			return m_str.compare(str);
		}

		//�w��̕����A������Ŏn�܂邩�𔻒肷��
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

		//�w��̕�����ŏI��邩�𔻒肷��
		bool ends_with(char c)const noexcept{
			return m_str[m_str.size() - 1] == c;
		}
		bool ends_with(const char* c)const noexcept{
			//�������J�E���g
			int len = 0;
			for (len = 0; c[len] != '\0';)
				len++;

			//���������傫���ꍇ
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
