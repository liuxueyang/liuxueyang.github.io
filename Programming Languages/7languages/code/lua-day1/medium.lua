function for_loop(a, b, f)
   local i = a;
   while i <= b do
      f()
      i = i + 1
   end
end

function hello()
   print("Hello, World")
end

for_loop(2, 3, hello)
