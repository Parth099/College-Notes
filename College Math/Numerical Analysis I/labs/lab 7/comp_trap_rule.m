function area = comp_trap_rule(f, a, b, n)

    h = (b-a)./n;
    
    internal = 0;

    for i = 1:n-1
        j = a + i*h;
        internal = internal + f(j);

    end

    area = (h./2)*(f(a) + f(b) + 2.*internal);
end