-- Date: 2018/12/3 00:05:16 Monday

function ends_in_3(num)
   return num % 10 == 3
end

function is_prime(num)
   if num == 1 then
      return false
   end
   
   local sqrt_num = math.floor(math.sqrt(num))
      
   for i = 2, sqrt_num do
      if num % i == 0 then
         return false
      end
   end

   return true
end

function n_prime_end3(n)
   local cnt = 0
   local i = 1

   while cnt < n do
      if is_prime(i) and ends_in_3(i) then
         print(i)
         cnt = cnt + 1
      end
      i = i + 1
   end
end

n_prime_end3(10)

-- for i = 1, 30 do
--    end3 = ends_in_3(i)
   
--    if end3 then
--       print(i .. " ends with 3")
--    end

--    prime = is_prime(i)

--    if prime then
--       print(i .. " is prime")
--    end
-- end
