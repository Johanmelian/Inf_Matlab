Ts = 0.01; % Tu tiempo de muestreo
tau = 0.1; % El retardo de tu dirección en segundos
sys_c = tf(1, [tau 1]); % Sistema continuo
sys_d = c2d(sys_c, Ts, 'zoh'); % Conversión a discreto
[num_d, den_d] = tfdata(sys_d, 'v'); % Extraer coeficientes