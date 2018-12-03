function reduce(max, init, f)
   local res = init
   for i = 1, max do
      res = f(res, i)
   end
   
   return res
end

function add(previous, next)
   return previous + next
end

print(reduce(5, 0, add))

function multi(previous, next)
   return previous * next
end

function factorial(n)
   return reduce(n, 1, multi)
end

print(factorial(5))
