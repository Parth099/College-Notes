function [p,i] = fpi(p0,g,Nmax,tol)
%FPI
% This program solves the scalar-valued equation g(x)=x using the 
% fixed point iteration to a given tolerance accuracy
%
% INPUTS: 
%         p0 - the initial approximation
%         g - function for fixed point problem
%      Nmax - Maximum number of iterations (an integer)
%       tol - Solution tolerance
% OUTPUTS
%         p - Solution to the problem
%         i - Number of iterations taken 
%
% Written by Rujeko Chinomona
% MATH3043 @ Temple University 
% Fall 2022

i=1;  

while i<=Nmax 
    p = g(p0);   % Compute i^{th} approximation to p
    if abs(p-p0)<=tol
        break
    end
    i = i+1;
    p0 = p;  % Update p0
    if i > Nmax
        fprintf('Method failed after the max number of iterations allowed: %d iterations.\n',Nmax);
    end
end 