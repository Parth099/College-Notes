% In this script, we approximate eˆ(−5) using a Taylor polynomial of degree
% nine and compute the associated absolute errors
% Written by Parth Patel

clear % clears the workspace
format long % Displays more digits

e_neg_5_deg_9_method1 = exptaylorsum(9, -5);
e_neg_5_deg_9_method2 = 1/exptaylorsum(9, 5);
e_neg_5 = exp(-5);

disp("e^-5 is approximately "+ e_neg_5_deg_9_method1 + " using method A");
disp("absolute error with method A: "+ abs(e_neg_5_deg_9_method1 - e_neg_5) + newline)

disp("e^-5 is approximately "+ e_neg_5_deg_9_method2 + " using method B");
disp("absolute error with method B: "+ abs(e_neg_5_deg_9_method2 - e_neg_5) + newline)

% Why method B is a lot better than method B ?
%
% Method B is better than method A because we are trying to find a negative 
% exponent for e. When calculating the sum, we notice that each term of an 
% even degree is positive, and each term of an odd degree is negative.Since
% the sum oscillates, it requires more terms to converge to a better approximation. 
% 
% This does not occur in B since we take the inverse after completing the 
% summation, and we do not have to deal with the oscillation.


%functions at the bottom

%obtains the value of a single term
function [value] = taylorterm(termnumber, x)
    value = (x ^ termnumber) / factorial(termnumber);
end

%sums the terms from the $taylorterm function
function [e_value] = exptaylorsum(degree, x)
    e_value = 0;
    for termnumber = 0:1:degree
        e_value = e_value + taylorterm(termnumber, x); 
    end
end
