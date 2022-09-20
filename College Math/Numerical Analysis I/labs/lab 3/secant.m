function [p,i] = secant(f,p0,p1,Nmax,tol)
%[p,i] = secant(f,po,p1,Nmax,tol)
% This program solves the scalar-valued equation f(x)=0 using the Secant 
% method to a given tolerance accuracy
%
% INPUTS: 
%         f - Root-finding function defined as an anonymous Matlab function.
%        p0 - initial guess
%        p1 - initial second guess
%      Nmax - Maximum number of iterations (an integer)
%       tol - Solution tolerance
% OUTPUTS
%         p - Solution to the problem
%         i - Number of iterations it takes to get convergence
%        
% Written by Parth Patel
% MATH3043 @ Temple University 
% Fall 2022

i = 2;
q0 = f(p0);
q1= f(p1);

fprintf('i = %4d, p = %.10e\n',0, p0);
fprintf('i = %4d, p = %.10e\n',1, p1);

while i <= Nmax
    p = ((q0*p1)-(q1*p0)) / (q0-q1); % alternate from from quiz 2
    fprintf('i = %4d, p = %.10e\n',i, p);

    if abs(p0 - p) < tol
        break;
    end

    % set up next p0
    p0 = p1;
    q0 = q1; % no need to recalc f(p1)

    % set up next p1
    p1 = p;
    q1 = f(p1);

    i = i + 1;
    if i > Nmax
        fprintf(['Method failed to reach desired tolerance after \n' ...
            ' the max number of iterations allowed: %d iterations.\n'],Nmax);
    end

   
end
end