#include "Statistics.hpp"

#include "gtest/gtest.h"

TEST(TestSuite, test_statistics)
{
    std::vector<double> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    double population_std = 2.5820; // taken from wolfram alpha

    auto avg = Statistics::average(data);
    ASSERT_DOUBLE_EQ(avg, 5);

    auto std_ = Statistics::standard_deviation(data, avg);
    auto var = Statistics::variance(data, avg);

    EXPECT_NEAR(std_, population_std, 0.01);
    EXPECT_NEAR(var, population_std * population_std, 0.01);

    auto sample_std = Statistics::sample_deviation(std_, 100);

    EXPECT_NEAR(sample_std, population_std / 10, 0.01);

    double std_1 = Statistics::add_standard_deviations(0, 0);
    ASSERT_DOUBLE_EQ(std_1, 0);

    double std_2 = Statistics::add_standard_deviations(1, 1);
    ASSERT_DOUBLE_EQ(std_2, M_SQRT2);

    //    double Statistics::update_mean();

    //    double update_variance(double variance, double mean, int tot_samples, double new_sample);
    //
    //    double normalCDF(double value);
    //
    //    double find_cdf_quantile(double target_quantile, double precision);
    //
    //    ASSERT_FLOAT_EQ(c.strength, 20);
    //    ASSERT_FLOAT_EQ(c.agility, 30);
}