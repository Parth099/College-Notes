% returns idx for which arr[idx] == idx
function idx = idx_eq_val(arr)
    L = 1; %left pointer
    R = length(arr); %right pointer

    while L < R

        %check end points
        if arr(L) == L
           break 
        end

        if arr(R) == R
           L = R;
           break 
        end

        %find midpoint
        M = floor((L + R) / 2);

        if arr(M) > M
           R = M - 1; 
        elseif arr(M) < M
           L = M + 1; 
        else
            % we found the value for idx in the middle
            L = M;
            break;
        end
    end

    %see why loop was broken
    if arr(L) == L
        idx = L;
    else
        idx = -1;
    end
end