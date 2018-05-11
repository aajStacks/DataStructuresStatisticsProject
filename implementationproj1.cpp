#include<iostream>
#include<algorithm>
#include<cassert>
using namespace std;
#include "stats.h"
namespace main_savitch_2C
{
	statistician::statistician(){
		count = 0;
		tinyest = 0;
		largest = 0;
		total = 0;
	}
	void statistician::next(double r){
		if (count == 0){
			tinyest = r;
			largest = r;
		}
		count++;
		total = total + r;
		if (r < tinyest){
			tinyest = r;
		}
		if (r>largest){
			largest = r;
		}
		return;
	}
	void statistician::reset(){
		count = 0;
		tinyest = 0;
		largest = 0;
		total = 0;
		return;
	}
	statistician operator + (const statistician& s1, const statistician& s2){
		statistician temp;
		temp.count = s1.count + s2.count;
		temp.total = s1.total + s2.total;
		if (s1.tinyest <= s2.tinyest){
			temp.tinyest = s1.tinyest;
		}
		else{
			temp.tinyest = s2.tinyest;
		}
		if (s1.largest >= s2.largest){
			temp.largest=s1.largest;
		}
		else{
			temp.largest = s2.largest;
		}
		return temp;
	}
	statistician operator * (double scale, const statistician& s){
		statistician temp;
		if (scale >= 0){
			temp.count = scale*s.count;
			temp.total = scale*s.total;
			temp.tinyest = scale*s.tinyest;
			temp.largest = scale*s.largest;
		}
		return temp;
	}
	bool operator == (const statistician& s1, const statistician& s2){
		if (s1.length() != s2.length()){
			return false;
		}
		if (s1.sum() != s2.sum()){
			return false;
		}
		if (s1.minimum() != s2.minimum()){
			return false;
		}
		if (s1.maximum() != s2.maximum()){
			return false;
		}
		return true;
	}
}