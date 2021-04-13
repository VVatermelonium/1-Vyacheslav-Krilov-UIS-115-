#pragma once
class money
{
private:
	int count10;
	int count50;
	int count100;
	int count500;
	int count1000;
public:
	void set_all(int c10, int c50, int c100, int c500, int c1000) {
		count10 = c10;
		count50 = c50;
		count100 = c100;
		count500 = c500;
		count1000 = c1000;
	}
	int now() const {
		return count10 * 10 + count50 * 50 + count100 * 100 + count500 * 500 + count1000 * 1000;
	}
	int get_count10() const {
		return count10;
	}
	int get_count50() const {
		return count50;
	}
	int get_count100() const {
		return count100;
	}
	int get_count500() const {
		return count500;
	}
	int get_count1000() const {
		return count1000;
	}
	void load(int c10, int c50, int c100, int c500, int c1000) {
		count10 += c10;
		count50 += c50;
		count100 += c100;
		count500 += c500;
		count1000 += c1000;
	}
	void extract(int c10, int c50, int c100, int c500, int c1000) {
		count10 -= c10;
		count50 -= c50;
		count100 -= c100;
		count500 -= c500;
		count1000 -= c1000;
	}
};

