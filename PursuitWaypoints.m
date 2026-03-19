Ts = 1/500;

%% Pursuit waypoints
simData = load('Scenario.mat');
%simData = load('ScenarioStraight_v2.mat');

%% define reference points
refPose = simData.data.ActorSpecifications.Waypoints;
xRef = refPose(:,1);
yRef = -refPose(:,2);

%% Creamos un vector con 10 veces más puntos intermedios
puntos_finos = linspace(1, length(xRef), length(xRef)*10); 

% Interpolamos usando 'spline' para redondear las esquinas
xRef = interp1(1:length(xRef), xRef, puntos_finos, 'spline')';
yRef = interp1(1:length(yRef), yRef, puntos_finos, 'spline')';

%% define parameters used in the models
X_o = refPose(1,1);    % initial vehicle position
Y_o = -refPose(1,2);   % initial vehicle position 
X_end = refPose(end,1);
Y_end = -refPose(end,2);
psi_o = 0;             % initial yaw angle

s = size(xRef);
tRef = (linspace(0, Ts, s(1)))';
