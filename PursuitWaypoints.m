%% Pursuit waypoints
load('Scenario.mat')
%load('ScenarioStraight_v2.mat')

%% define reference points
refPose = data.ActorSpecifications.Waypoints;
xRef = refPose(:,1);
yRef = -refPose(:,2);

%% Creamos un vector con 10 veces más puntos intermedios
puntos_finos = linspace(1, length(xRef), length(xRef)*10); 

% Interpolamos usando 'spline' para redondear las esquinas
xRef = interp1(1:length(xRef), xRef, puntos_finos, 'spline')';
yRef = interp1(1:length(yRef), yRef, puntos_finos, 'spline')';

%% define reference time for plotting 
Ts = 200; % simulation time
s = size(xRef);
tRef = (linspace(0,Ts,s(1)))'; % this time variable is used in the "2D Visualization" block for plotting the reference points. 

%% define parameters used in the models
L = 1; % bicycle length
ld = 3; % lookahead distance
X_o = refPose(1,1); % initial vehicle position
Y_o = -refPose(1,2); % initial vehicle position 
X_end = refPose(end,1);
Y_end = -refPose(end,2);
psi_o = 0; % initial yaw angle