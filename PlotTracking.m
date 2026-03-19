plot(yRef, xRef, 'g--', 'LineWidth', 3); hold on;
plot(out.yFb.Data, out.xFb.Data, 'r-', 'LineWidth', 4); hold on;
plot(out.yFb2.Data, out.xFb2.Data, 'b--', 'LineWidth', 4); hold on;
legend('Ref', 'Modelo protegido', 'Modelo normal')
title('Trayectoria XY del Robot');
xlabel('Posición Y (m)');
ylabel('Posición X (m)');
grid on;