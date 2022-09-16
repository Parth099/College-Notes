function [p,nit] = bisection(f,a,b,Nmax,tol)
%BISECTION
% This program solves the scalar-valued equation f(x)=0 using the 
% bisection method to a given tolerance accuracy
%
% INPUTS: 
%         f - Root-finding function defined as an anonymous Matlab function.
%         a - Left end point of interval containing solution
%         b - Right end point of interval containing solution 
%      Nmax - Maximum number of iterations (an integer)
%       tol - Solution tolerance
% OUTPUTS
%         p - Solution to the problem
%     nit - Number of iterations it takes to get convergence
%        
% Written by Parth Patel
% MATH3043 @ Temple University 
% Fall 2022

nit = 0;
p = a + ((b - a) / 2);
while nit < Nmax && abs(f(p)) > tol
   A = f(a);
   if A * f(p) > 0
        a = p;
   else
        b = p;
   end
    
   p = a + ((b - a) / 2);
   nit = nit + 1;
end %end while
end 
