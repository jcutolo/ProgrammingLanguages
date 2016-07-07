-- Joshua Cutolo
-- CSC 322 Assignment 2
-- Due Date: February 19th, 2015

-- The h3 function for Towers of Hanoi
h3 :: Int -> Integer
h3 0 = 0
h3 n = 2 * h3 (n - 1) + 1

-- The h4 function for Towers of Hanoi
h4 :: Int -> Integer
h4 0 = 0
h4 n = minimum [2 * h4 (k) + h3 (n - k) | k <- [0..n-1] ]

-- The memoized h4 function for Towers of Hanoi
memoized_h4 :: Int -> Integer
memoized_h4 = (map h4 [0..] !!)
	      where h4 0 = 0
	            h4 n = minimum [2 * memoized_h4 (k) + h3 (n - k) | k <- [0..n-1] ]

-- The memoized h5 function for Towers of Hanoi
memoized_h5 :: Int -> Integer
memoized_h5 = (map h5 [0..] !!)
	      where h5 0 = 0
		    h5 n = minimum [2 * memoized_h5 (k) + memoized_h4 (n - k) | k <- [0..n-1] ]

-- The value of memoized_h4 100 = 172033, which means it will take 172033 steps to finish the tower of Hanoi of 100 disks,
-- using 4 towers.
-- The value of memoized_h5 64 = 1535, which means it will take 1535 steps to finish the tower of Hanoi of 64 disks,
-- using 5 towers.
