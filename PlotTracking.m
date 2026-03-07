plot(xRef, yRef, 'b--', 'LineWidth', 1); hold on;
plot(out.xFb.Data, out.yFb.Data, 'r-', 'LineWidth', 2); hold on;
title('Trayectoria XY del Robot');
xlabel('Posición X (m)');
ylabel('Posición Y (m)');
grid on;