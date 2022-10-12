function S = cubicspline(x, y)
    dim = length(x);

    % takes n - 1 functions to connect n points
    S = zeros(dim, 4);

    % row vector
    h = zeros(dim, 1);
    
    %STEP 1
    for j = 1:dim-1
        h(j) = x(j+1) - x(j);
    end
    
    disp("H:");
    disp(h);
    
    alp = zeros(dim, 1);
    
    %STEP 2
    for i = 2:dim-1
        
        p1 = (3./h(i))    *(y(i+1) - y(i));
        p2 = (3./h(i - 1))*(y(i) - y(i - 1));

        alp(i) = p1 - p2;
    end


    %STEP 3
    l  = zeros(dim, 1);
    mu = zeros(dim, 1);
    z  = zeros(dim, 1);
    
    %STEP 4
    for i = 2:dim-1
        l(i) = 2*(x(i + 1) - x(i - 1)) - (h(i - 1)*mu(i - 1));
        mu(i) = h(i)/l(i);
        z(i) = (alp(i) - (h(i - 1) * z(i - 1))) / l(i);
    end 
    
    %STEP 5
    l(dim) = 1;

    %STEP 6
    for j = dim-1:-1:1
        S(j, 1) = y(j); 
        S(j, 3) = z(j) - (mu(j) * S(j+1, 3));
        S(j, 2) = (y(j + 1) - y(j))/(h(j)) - (h(j)*(S(j + 1, 3) + 2*S(j, 3))) / 3;
        S(j, 4) = (S(j + 1, 3) - S(j, 3))/(3*h(j));
    end

    S(dim, :) = []; % i use an extra row for padding so the algo doesnt go out of bounds
end