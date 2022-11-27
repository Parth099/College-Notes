function [x, num_iter] = GaussSeidel(A, b, x0, max_iter, TOL)
    N = length(A);
    x = x0;
    num_iter = 0; 

    while num_iter < max_iter
        x = b;
        for i = 1:N
            i_sum = 0;
            % for j < i use x(i) 
            for j = 1: i - 1
                i_sum = i_sum + x(j)*A(i, j);
            end

            % for j > i <= N use x0(i)
            for j = i + 1: N
                i_sum = i_sum + x0(j)*A(i, j);
            end
            x(i) = (1./A(i, i)) .* (x(i) - i_sum);
        end

        if norm(x - x0, inf) < TOL
            return
        end

        num_iter = num_iter + 1;
        x0 = x;
    end
    
    fprintf("exeeded %d iterations", max_iter);
end

