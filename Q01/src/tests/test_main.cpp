#include "test_main.hpp"
#include <iostream>

TEST(PriorityQueue, find_str01) {
	SpecPriorityQueue<SomeObject, std::vector<SomeObject>, cmp> pq;
	SomeObject obj1(1, "obj1");
	pq.push(obj1);

	SomeObject obj2(2, "obj2");
	pq.push(obj2);

	auto it = pq.find("obj2");
	ASSERT_EQ("obj2", it->getIdentifier());
	ASSERT_EQ(2, it->getPrioprity());
}

TEST(PriorityQueue, find_str02) {
	SpecPriorityQueue<SomeObject, std::vector<SomeObject>, cmp> pq;
	SomeObject obj1(1, "obj1");
	pq.push(obj1);

	SomeObject obj2(2, "obj2");
	pq.push(obj2);

	auto it = pq.find("obj1");
	ASSERT_EQ("obj1", it->getIdentifier());
	ASSERT_EQ(1, it->getPrioprity());
}

TEST(PriorityQueue, find_str03) {
	SpecPriorityQueue<SomeObject, std::vector<SomeObject>, cmp> pq;
	for (int i = 1; i < 21; i++) {
		std::string serial = "obj";
		serial.append(std::to_string(i));
		SomeObject tempObj(i, serial);
		pq.push(tempObj);
	}
	SomeObject duplicatePrio(10, "duplicaTEN");
	pq.push(duplicatePrio);
	auto it = pq.find("obj10");
	ASSERT_EQ("obj10", it->getIdentifier());
	ASSERT_EQ(10, it->getPrioprity());
	pq.remove(it);
	it = pq.find("obj10");
	ASSERT_EQ(it, pq.end());
	it = pq.find("duplicaTEN");
	ASSERT_EQ(it->getPrioprity(), 10);
	ASSERT_EQ(it->getIdentifier(), "duplicaTEN");
	pq.remove(it);
	it = pq.find("duplicaTEN");
	ASSERT_EQ(it, pq.end());
}

TEST(PriorityQueue, find_int01) {
	SpecPriorityQueue<SomeObject, std::vector<SomeObject>, cmp> pq;
	SomeObject obj1(1, "obj1");
	pq.push(obj1);

	SomeObject obj2(2, "obj2");
	pq.push(obj2);

	auto it = pq.find(1);
	ASSERT_EQ("obj1", it->getIdentifier());
	ASSERT_EQ(1, it->getPrioprity());
}

TEST(PriorityQueue, find_int02) {
	SpecPriorityQueue<SomeObject, std::vector<SomeObject>, cmp> pq;
	SomeObject obj1(1, "obj1");
	pq.push(obj1);

	SomeObject obj2(2, "obj2");
	pq.push(obj2);

	auto it = pq.find(2);
	ASSERT_EQ("obj2", it->getIdentifier());
	ASSERT_EQ(2, it->getPrioprity());
}

TEST(PriorityQueue, find_int03) {
	SpecPriorityQueue<SomeObject, std::vector<SomeObject>, cmp> pq;
	for (int i = 1; i < 21; i++) {
		std::string serial = "obj";
		serial.append(std::to_string(i));
		SomeObject tempObj(i, serial);
		pq.push(tempObj);
	}
	SomeObject duplicatePrio(10, "duplicaTEN");
	pq.push(duplicatePrio);
	auto it = pq.find(10);
	ASSERT_EQ("obj10", it->getIdentifier());
	ASSERT_EQ(10, it->getPrioprity());
	pq.remove(it);
	it = pq.find(10);
	ASSERT_EQ(it->getPrioprity(), 10);
	ASSERT_EQ(it->getIdentifier(), "duplicaTEN");
	pq.remove(it);
	it = pq.find(10);
	ASSERT_EQ(it, pq.end());
}

TEST(PriorityQueue, print_all) {
	SpecPriorityQueue<SomeObject, std::vector<SomeObject>, cmp> pq;
	for (int i = 1; i < 21; i++) {
		std::string serial = "obj";
		serial.append(std::to_string(i));
		SomeObject tempObj(i, serial);
		pq.push(tempObj);
	}
	SomeObject duplicatePrio(10, "duplicaTEN");
	pq.push(duplicatePrio);
	pq.print_all();
}

TEST(PriorityQueue, print_all_regr_twice) {
	SpecPriorityQueue<SomeObject, std::vector<SomeObject>, cmp> pq;
	for (int i = 20; i > 0; i--) {
		std::string serial = "obj";
		serial.append(std::to_string(i));
		SomeObject tempObj(i, serial);
		pq.push(tempObj);
	}
	SomeObject duplicatePrio(10, "duplicaTEN");
	pq.push(duplicatePrio);
	pq.print_all();
	pq.print_all();
}

TEST(PriorityQueue, check_order_asc) {
	SpecPriorityQueue<SomeObject, std::vector<SomeObject>, cmp> pq;
	for (int i = 1; i < 4; i++) {
		std::string serial = "obj";
		serial.append(std::to_string(i));
		SomeObject tempObj(i, serial);
		pq.push(tempObj);
	}
	SomeObject duplicatePrio(2, "duplicate2");
	pq.push(duplicatePrio);
	ASSERT_EQ(pq.top().getPrioprity(), 1);
	ASSERT_EQ(pq.top().getIdentifier(), "obj1");
	pq.pop();
	ASSERT_EQ(pq.top().getPrioprity(), 2);
	ASSERT_EQ(pq.top().getIdentifier(), "obj2");
	pq.pop();
	ASSERT_EQ(pq.top().getPrioprity(), 2);
	ASSERT_EQ(pq.top().getIdentifier(), "duplicate2");
	pq.pop();
	ASSERT_EQ(pq.top().getPrioprity(), 3);
	ASSERT_EQ(pq.top().getIdentifier(), "obj3");
}

TEST(SomeObject, range_001){
	SomeObject so(1, "lala");
	ASSERT_EQ(so.getPrioprity(), 1);
	ASSERT_EQ(so.getIdentifier(), "lala");
}

TEST(SomeObject, range_002){
	ASSERT_ANY_THROW(SomeObject so(0, "lala"));
}

TEST(SomeObject, range_003){
	ASSERT_ANY_THROW(SomeObject so(-1, "lala"));
}

TEST(SomeObject, range_004){
	ASSERT_ANY_THROW(SomeObject so(21, "lala"));
}

TEST(IMPL_str_sz, sizeIsOne){
	std::string str("X");
	ASSERT_EQ(str.size(), 1);
}