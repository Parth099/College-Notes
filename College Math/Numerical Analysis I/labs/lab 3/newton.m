function [p,i] = newton(f,df,p0,Nmax,tol)
%[p,i] = newton(f,df,p0,Nmax,tol)
% This program solves the scalar-valued equation f(x)=0 using Newton's 
% method to a given tolerance accuracy
%
% INPUTS: 
%         f - Root-finding function defined as an anonymous Matlab function.
%        df - Derivative of f 
%        p0 - initial guess
%      Nmax - Maximum number of iterations (an integer)
%       tol - Solution tolerance
% OUTPUTS
%         p - Solution to the problem
%         i - Number of iterations it takes to get convergence
%        
% Written by Rujeko Chinomona
% MATH3043 @ Temple University 
% Fall 2022

i=1; 
fprintf('i = %4d, p = %.10e\n',i-1,p0);

while i<=Nmax
    p = p0 - f(p0)/df(p0);  % Compute i^{th} approximation to p
    fprintf('i = %4d, p = %.15e\n',i,p);
    if abs(p-p0)<tol        % if tolerance satisfied, solution found
        break
    end
    i=i+1; 
    p0 = p;                 % Update p0
    if i > Nmax
        fprintf(['Method failed to reach desired tolerance after \n' ...
            ' the max number of iterations allowed: %d iterations.\n'],Nmax);
    end
end
end