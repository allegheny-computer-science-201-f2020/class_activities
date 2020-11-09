-- type `ghci`
-- load `:l functions`
-- run  `fact 10`
-- run  `sub 10`
-- run  `square 10`

fact n
  |  n == 0 = 1
  |  n > 0 = n * fact(n - 1)

sub n
  | n < 10 = 0
  | n > 100 = 2
  | otherwise = 1

square x = x * x
