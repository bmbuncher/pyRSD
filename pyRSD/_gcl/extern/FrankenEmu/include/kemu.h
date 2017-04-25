/*
 *  kemu.h
 *
 *
 *  Created by Earl Lawrence on 12/14/09.
 *  Updated 11/25/2012.
 *
 *  This program was prepared by Los Alamos National Security, LLC at Los Alamos National Laboratory (LANL)
 *  under contract No. DE-AC52-06NA25396 with the U.S. Department of Energy (DOE). All rights in the program
 *  are reserved by the DOE and Los Alamos National Security, LLC.  Permission is granted to the public to
 *  copy and use this software without charge, provided that this Notice and any statement of authorship are
 *  reproduced on all copies.  Neither the U.S. Government nor LANS makes any warranty, express or implied,
 *  or assumes any liability or responsibility for the use of this software.
 *
 */


static double kemu[500] =
{0.0008694,
 0.00088557,
 0.00090204,
 0.00091882,
 0.00093591,
 0.00095332,
 0.00097105,
 0.00098911,
 0.0010075,
 0.0010262,
 0.0010453,
 0.0010648,
 0.0010846,
 0.0011048,
 0.0011253,
 0.0011462,
 0.0011675,
 0.0011893,
 0.0012114,
 0.0012339,
 0.0012569,
 0.0012802,
 0.0013041,
 0.0013283,
 0.001353,
 0.0013782,
 0.0014038,
 0.0014299,
 0.0014565,
 0.0014836,
 0.0015112,
 0.0015393,
 0.0015679,
 0.0015971,
 0.0016268,
 0.0016571,
 0.0016879,
 0.0017193,
 0.0017513,
 0.0017838,
 0.001817,
 0.0018508,
 0.0018852,
 0.0019203,
 0.001956,
 0.0019924,
 0.0020294,
 0.0020672,
 0.0021056,
 0.0021448,
 0.0021847,
 0.0022253,
 0.0022667,
 0.0023089,
 0.0023518,
 0.0023956,
 0.0024401,
 0.0024855,
 0.0025317,
 0.0025788,
 0.0026268,
 0.0026757,
 0.0027254,
 0.0027761,
 0.0028277,
 0.0028803,
 0.0029339,
 0.0029885,
 0.0030441,
 0.0031007,
 0.0031584,
 0.0032171,
 0.0032769,
 0.0033379,
 0.0034,
 0.0034632,
 0.0035276,
 0.0035932,
 0.0036601,
 0.0037281,
 0.0037975,
 0.0038681,
 0.0039401,
 0.0040133,
 0.004088,
 0.004164,
 0.0042415,
 0.0043204,
 0.0044007,
 0.0044826,
 0.0045659,
 0.0046509,
 0.0047374,
 0.0048255,
 0.0049152,
 0.0050067,
 0.0050998,
 0.0051946,
 0.0052912,
 0.0053897,
 0.0054899,
 0.005592,
 0.005696,
 0.005802,
 0.0059099,
 0.0060198,
 0.0061318,
 0.0062458,
 0.006362,
 0.0064803,
 0.0066008,
 0.0067236,
 0.0068487,
 0.006976,
 0.0071058,
 0.007238,
 0.0073726,
 0.0075097,
 0.0076494,
 0.0077917,
 0.0079366,
 0.0080842,
 0.0082346,
 0.0083877,
 0.0085437,
 0.0087026,
 0.0088645,
 0.0090294,
 0.0091973,
 0.0093684,
 0.0095426,
 0.0097201,
 0.0099009,
 0.010085,
 0.010273,
 0.010464,
 0.010658,
 0.010857,
 0.011058,
 0.011264,
 0.011474,
 0.011687,
 0.011904,
 0.012126,
 0.012351,
 0.012581,
 0.012815,
 0.013053,
 0.013296,
 0.013544,
 0.013795,
 0.014052,
 0.014313,
 0.01458,
 0.014851,
 0.015127,
 0.015408,
 0.015695,
 0.015987,
 0.016284,
 0.016587,
 0.016896,
 0.01721,
 0.01753,
 0.017856,
 0.018188,
 0.018526,
 0.018871,
 0.019222,
 0.01958,
 0.019944,
 0.020315,
 0.020693,
 0.021077,
 0.021469,
 0.021869,
 0.022275,
 0.02269,
 0.023112,
 0.023542,
 0.02398,
 0.024426,
 0.02488,
 0.025343,
 0.025814,
 0.026294,
 0.026783,
 0.027281,
 0.027789,
 0.028306,
 0.028832,
 0.029368,
 0.029915,
 0.030471,
 0.031038,
 0.031615,
 0.032203,
 0.032802,
 0.033412,
 0.034033,
 0.034666,
 0.035311,
 0.035968,
 0.036637,
 0.037318,
 0.038013,
 0.03872,
 0.03944,
 0.040173,
 0.04092,
 0.041682,
 0.042457,
 0.043247,
 0.044051,
 0.04487,
 0.045705,
 0.046555,
 0.047421,
 0.048303,
 0.049201,
 0.050116,
 0.051048,
 0.051998,
 0.052965,
 0.05395,
 0.054954,
 0.055976,
 0.057017,
 0.058077,
 0.059157,
 0.060258,
 0.061379,
 0.06252,
 0.063683,
 0.064867,
 0.066074,
 0.067303,
 0.068555,
 0.06983,
 0.071129,
 0.072452,
 0.073799,
 0.075172,
 0.07657,
 0.077994,
 0.079445,
 0.080922,
 0.082427,
 0.083961,
 0.085522,
 0.087113,
 0.088733,
 0.090383,
 0.092065,
 0.093777,
 0.095521,
 0.097298,
 0.099107,
 0.10095,
 0.10283,
 0.10474,
 0.10669,
 0.10867,
 0.11069,
 0.11275,
 0.11485,
 0.11699,
 0.11916,
 0.12138,
 0.12364,
 0.12594,
 0.12828,
 0.13066,
 0.13309,
 0.13557,
 0.13809,
 0.14066,
 0.14328,
 0.14594,
 0.14866,
 0.15142,
 0.15424,
 0.15711,
 0.16003,
 0.163,
 0.16604,
 0.16912,
 0.17227,
 0.17547,
 0.17874,
 0.18206,
 0.18545,
 0.1889,
 0.19241,
 0.19599,
 0.19964,
 0.20335,
 0.20713,
 0.21098,
 0.21491,
 0.2189,
 0.22298,
 0.22712,
 0.23135,
 0.23565,
 0.24003,
 0.2445,
 0.24905,
 0.25368,
 0.2584,
 0.2632,
 0.2681,
 0.27308,
 0.27816,
 0.28334,
 0.28861,
 0.29397,
 0.29944,
 0.30501,
 0.31068,
 0.31646,
 0.32235,
 0.32835,
 0.33445,
 0.34067,
 0.34701,
 0.35346,
 0.36004,
 0.36673,
 0.37356,
 0.3805,
 0.38758,
 0.39479,
 0.40213,
 0.40961,
 0.41723,
 0.42499,
 0.43289,
 0.44095,
 0.44915,
 0.4575,
 0.46601,
 0.47468,
 0.48351,
 0.4925,
 0.50166,
 0.51099,
 0.5205,
 0.53018,
 0.54004,
 0.55008,
 0.56031,
 0.57073,
 0.58135,
 0.59216,
 0.60318,
 0.6144,
 0.62582,
 0.63746,
 0.64932,
 0.6614,
 0.6737,
 0.68623,
 0.69899,
 0.71199,
 0.72524,
 0.73872,
 0.75246,
 0.76646,
 0.78072,
 0.79524,
 0.81003,
 0.82509,
 0.84044,
 0.85607,
 0.87199,
 0.88821,
 0.90473,
 0.92156,
 0.9387,
 0.95616,
 0.97394,
 0.99206,
 1.0105,
 1.0293,
 1.0485,
 1.068,
 1.0878,
 1.108,
 1.1287,
 1.1496,
 1.171,
 1.1928,
 1.215,
 1.2376,
 1.2606,
 1.2841,
 1.3079,
 1.3323,
 1.3571,
 1.3823,
 1.408,
 1.4342,
 1.4609,
 1.488,
 1.5157,
 1.5439,
 1.5726,
 1.6019,
 1.6317,
 1.662,
 1.6929,
 1.7244,
 1.7565,
 1.7892,
 1.8224,
 1.8563,
 1.8909,
 1.926,
 1.9618,
 1.9983,
 2.0355,
 2.0734,
 2.1119,
 2.1512,
 2.1912,
 2.232,
 2.2735,
 2.3158,
 2.3588,
 2.4027,
 2.4474,
 2.4929,
 2.5393,
 2.5865,
 2.6346,
 2.6836,
 2.7336,
 2.7844,
 2.8362,
 2.8889,
 2.9427,
 2.9974,
 3.0531,
 3.1099,
 3.1678,
 3.2267,
 3.2867,
 3.3478,
 3.4101,
 3.4735,
 3.5381,
 3.604,
 3.671,
 3.7393,
 3.8088,
 3.8797,
 3.9518,
 4.0253,
 4.1002,
 4.1764,
 4.2541,
 4.3332,
 4.4138,
 4.4959,
 4.5796,
 4.6647,
 4.7515,
 4.8399,
 4.9299,
 5.0216,
 5.115,
 5.2101,
 5.307,
 5.4057,
 5.5063,
 5.6087,
 5.713,
 5.8193,
 5.9275,
 6.0378,
 6.1501,
 6.2644,
 6.381,
 6.4996,
 6.6205,
 6.7437,
 6.8691,
 6.9969,
 7.127,
 7.2596,
 7.3946,
 7.5321,
 7.6722,
 7.8149,
 7.9603,
 8.1083,
 8.2591,
 8.4127,
 8.5692};