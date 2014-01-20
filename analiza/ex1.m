%
% I used the results on the slides: https://docs.google.com/viewer?a=v&pid=sites&srcid=ZGVmYXVsdGRvbWFpbnxicmlnaXR0ZWJyZWNrbmVyfGd4OjQxZjRkMDU1MjczYjUxYzI
% The results obtaned were:
% Ex2: the weight of the snake of length 55: 94.465 70: 202.343
% Ex3: forecast for 2010: 71.612 2013: 75.041
%

%% Initialization
clear ; close all; clc

%% ===================== Part 1: Reading Data =====================
data = load('ex3data.txt');
fprintf('Plotting data...\n');
X = data(:, 1); y = data(:, 2);
n = length(y); % number of training examples
minX = min(X);
maxX = max(X);

%% =================== Part 2: Plotting the data ==================

plot(X, y, 'rx', 'MarkerSize', 8); 
ylabel('Y');
xlabel('X');

fprintf('Program paused. Press enter to continue.\n');
pause;

%% ===================== Part 3: Finding beta =====================

xy = X .* y;
xySum = sum(xy);
beta(2) = (xySum - 1/n * sum(X) * sum(y))/(sum(X .^ 2) - 1/n * sum(X)^2);
beta(1) = (1/n * sum(y)) - (1/n * sum(X)) * beta(2);

fprintf('Beta found by linear regression: %f %f\n',beta(1),beta(2));
fprintf('Program paused. Press enter to continue.\n');
pause;

%% =============== Part 4: Plotting the predictions ===============

X = [ones(1,n);X']; % Add a line of ones to x

% Plot the predictions for the given data
hold on; % keep previous plot visible
plot(data(:,1), beta*X, '+');
range = [ones(1,(maxX-minX)*10+1);minX:0.1:maxX];
plot(minX:0.1:maxX,beta*range);
legend('Training data', 'Linear regression',"location", "northwest")
legend boxon;

%% ===================== Part 5: Finding e's' =====================

e=y' .- beta*X

%% ===================== Part 6: Predict data =====================

data = load("predict.txt");
fprintf('Predictions for input:');
disp(beta*[ones(1,length(data));data']);