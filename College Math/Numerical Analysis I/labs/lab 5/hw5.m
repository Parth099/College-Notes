% 4d

x4d = [-1, -.5, 0, 0.5];
y4d = [0.86199480, 0.95802009, 1.0986123, 1.2943767];

spl4d = cubicspline(x4d, y4d);

disp("Spline for 4.d:");
disp(spl4d);

% 6d

% this is S3 which has an interval of [0, 0.5]
S3_Constants = spl4d(3, :);

% ascii magic
MAGIC_NUMBER = 97 - 1;
a = S3_Constants('a' - MAGIC_NUMBER);
b = S3_Constants('b' - MAGIC_NUMBER);
c = S3_Constants('c' - MAGIC_NUMBER);
d = S3_Constants('d' - MAGIC_NUMBER);

% would be x_2 but matlab is 1-indexed
x3 = y4d(3);

f = @(x) a + b*x + c*(x.^2) + d*(x.^3);
df = @(x) b + 2*c*x + 3*d*(x.^3);


disp("Problem 6.2:");
disp(['S3(0.25)  = ', num2str(f(.25))]);
disp(['dS3(0.25) = ', num2str(df(0.25))]);









