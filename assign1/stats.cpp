// Provided by:   _________Xing Yang_____________
// Email Address: ___xyang004@citymail.cuny.edu_________________
#include "stats.h"
#include <assert.h>

using namespace std;
namespace main_savitch_2C
{
    statistician::statistician()
    {
        count = 0;
        total = 0;
    }
    void statistician::next(double r)
    {
        count ++;
        total += r;
        if (count == 1) {
            tinyest = r;
            largest = r;
        } else {
            if (r < tinyest) {
                tinyest = r;
            } else if (r > largest) {
                largest = r;
            }
        }
    }
    void statistician::reset()
    {
        count = 0;
        total = 0;
    }    
    double statistician::mean() const
    {
        assert(count > 0);
        return total/count;
    }
    double statistician::minimum() const
    {
        assert(count > 0);
        return tinyest;
    }
    double statistician::maximum() const
    {
        assert(count > 0);
        return largest;
    }
    main_savitch_2C::statistician operator + (const statistician& s1, const statistician& s2)
    {
        statistician s3;
        if(s1.count == 0) return s2;
        if(s2.count == 0) return s1;
        s3.count = s1.count + s2.count;
        s3.total = s1.sum() + s2.sum();
        if(s1.minimum() < s2.minimum())
            s3.tinyest = s1.minimum();
        else
            s3.tinyest = s2.minimum();
        if(s1.maximum() > s2.maximum())
            s3.largest = s1.maximum();
        else
            s3.largest = s2.maximum();
        return s3;
    }
    statistician operator * (double scale, const statistician& s)
    {
        statistician s3;
        if(s.count == 0)
            return s;
        s3.count = s.count;
        s3.total = s.count * s.mean() * scale;
        s3.tinyest = s.minimum() * scale;
        s3.largest = s.maximum() * scale;
        if(s3.tinyest > s3.largest)
        {
        	double a = s3.tinyest;
            s3.tinyest = s3.largest;
            s3.largest = a;
        }
        return s3;
    }
    bool operator ==(const statistician& s1, const statistician& s2)
    {
        if(s1.length() != s2.length())
            return false;
        if(s1.length() == 0 && s2.length() == 0)
            return true;
        if ((s1.mean() == s2.mean()) && (s1.sum() == s2.sum()) && (s1.minimum() == s2.minimum()) && (s1.maximum() == s2.maximum())){
        	return true;
        };
    }
}