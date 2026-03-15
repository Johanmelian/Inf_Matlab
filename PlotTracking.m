plot(yRef, xRef, 'b--', 'LineWidth', 1); hold on;
plot(out.yFb.Data, out.xFb.Data, 'r-', 'LineWidth', 2); hold on;
title('Trayectoria XY del Robot');
xlabel('Posición Y (m)');
ylabel('Posición X (m)');
grid on;