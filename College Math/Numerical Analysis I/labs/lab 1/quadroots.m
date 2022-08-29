function [x1,x2] = quadroots(a,b,c)
% This function gives the two roots of the quadratic equation
% given any inputs a, b, and c
% Written by Parth Patel

discrim = sqrt(b^2 - 4 * a * c);
values = [-b - discrim, -b + discrim];
roots = values ./ (2 * a);

x1 = roots(1);
x2 = roots(2);

end
