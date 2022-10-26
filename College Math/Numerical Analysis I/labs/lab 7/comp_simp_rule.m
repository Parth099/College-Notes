function area = comp_simp_rule(func, a, b, n)
    h = (b - a) / n;

    XI0 = func(a) + func(b);
    XI1 = 0;
    XI2 = 0;

    for i = 1:n-1
        Xi = a +i*h;
        
        if(mod(i, 2) == 0)
            XI2 = XI2 + func(Xi);

        else
            XI1 = XI1 + func(Xi);
 
        end

    end

    area = h*(XI0 + 2.*XI2 + 4.*XI1)./3;
end