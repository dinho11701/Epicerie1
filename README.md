# TP3 - INF3105

## Auteurs
Lysanne Chagnon (CHAL65550003)
Oswald Essongué (ESSO16019809)

## Auto-évaluation
Ce programme génère des trajets optimaux pour des missions contenant une seule destination.
Ce programme génère aussi des trajets optimaux pour des missions contenant plusieurs destinations (il n'est pas 
efficace, c'est pour celà que des tests de types F font un échec, car ils prennent trop de temps).

## Résultats des tests

Test            	Miss	CPU	Mém.(k)	Valid	Optimal	DistOK	RouteOK/Total	Réussi?
uqam-missions-0.txt	1	0.00	4060k	1	1	1	1	/1	Optimal
uqam-missions-1.txt	6	0.00	4124k	6	6	6	6	/6	Optimal
uqam-missions-D0.txt	1	0.00	3940k	1	1	1	1	/1	Optimal
uqam-missions-D1.txt	2	0.00	3892k	2	2	2	2	/2	Optimal
uqam-missions-D2.txt	10	0.00	4128k	10	10	10	10	/10	Optimal
uqam-missions-D3.txt	100	0.00	4004k	100	100	100	100	/100	Optimal
uqam-missions-D4.txt	500	0.00	4004k	500	500	500	500	/500	Optimal
uqam-missions-D5.txt	1000	0.01	4156k	1000	1000	1000	1000	/1000	Optimal
uqam-missions-D6.txt	5000	0.07	4236k	5000	5000	5000	5000	/5000	Optimal
uqam-missions-F02.txt	10	0.00	3956k	10	10	10	10	/10	Optimal
uqam-missions-F03.txt	10	0.00	4240k	10	10	10	10	/10	Optimal
uqam-missions-F04.txt	10	0.02	4232k	10	10	10	10	/10	Optimal
uqam-missions-F05.txt	10	0.12	3964k	10	10	10	10	/10	Optimal
uqam-missions-F07.txt	10	1.24	4004k	10	10	10	10	/10	Optimal
uqam-missions-F08.txt	10	7.08	4180k	10	10	10	10	/10	Optimal
uqam-missions-F09.txt	10	42.96	3960k	10	10	10	10	/10	Optimal
uqam-missions-F10.txt	10	60.04	3956k	0	0	0	0	/10	Echec
uqam-missions-F11.txt	10	60.03	3772k	0	0	0	0	/10	Echec
uqam-missions-F12.txt	10	60.00	3720k	0	0	0	0	/10	Echec
uqam-missions-F13.txt	10	59.99	3936k	0	0	0	0	/10	Echec
stejulie-missions-D0.txt	1	0.00	5276k	1	1	1	1	/1	Optimal
stejulie-missions-D1.txt	2	0.00	5584k	2	2	2	2	/2	Optimal
stejulie-missions-D2.txt	10	0.01	5752k	10	10	10	10	/10	Optimal
stejulie-missions-D3.txt	100	0.08	5868k	100	100	100	100	/100	Optimal
stejulie-missions-D4.txt	500	0.40	5612k	500	500	500	500	/500	Optimal
stejulie-missions-D5.txt	1000	0.82	5608k	1000	1000	1000	1000	/1000	Optimal
stejulie-missions-D6.txt	5000	4.08	5604k	5000	5000	5000	5000	/5000	Optimal
stejulie-missions-F02.txt	10	0.03	5676k	10	10	10	10	/10	Optimal
stejulie-missions-F03.txt	10	0.12	5844k	10	10	10	10	/10	Optimal
stejulie-missions-F04.txt	10	2.87	5832k	10	10	10	10	/10	Optimal
stejulie-missions-F05.txt	10	19.44	5604k	10	10	10	10	/10	Optimal
stejulie-missions-F07.txt	10	59.96	5532k	4	4	4	4	/10	Echec
stejulie-missions-F08.txt	10	59.99	5352k	0	0	0	0	/10	Echec
stejulie-missions-F09.txt	10	59.96	5268k	0	0	0	0	/10	Echec
stejulie-missions-F10.txt	10	59.91	5328k	0	0	0	0	/10	Echec
stejulie-missions-F11.txt	10	59.99	5456k	0	0	0	0	/10	Echec
stejulie-missions-F12.txt	10	59.99	5612k	0	0	0	0	/10	Echec
stejulie-missions-F13.txt	10	59.96	5448k	0	0	0	0	/10	Echec
montsthilaire-missions-D0.txt	1	0.01	7412k	1	1	1	1	/1	Optimal
montsthilaire-missions-D1.txt	2	0.01	7304k	2	2	2	2	/2	Optimal
montsthilaire-missions-D2.txt	10	0.04	7424k	10	10	10	10	/10	Optimal
montsthilaire-missions-D3.txt	100	0.21	7660k	100	100	100	100	/100	Optimal
montsthilaire-missions-D4.txt	500	1.08	7560k	500	500	500	500	/500	Optimal
montsthilaire-missions-D5.txt	1000	2.00	7856k	1000	1000	1000	1000	/1000	Optimal
montsthilaire-missions-D6.txt	5000	10.67	8060k	5000	5000	5000	5000	/5000	Optimal
montsthilaire-missions-F02.txt	10	0.06	7884k	10	10	10	10	/10	Optimal
montsthilaire-missions-F03.txt	10	0.34	7592k	10	10	10	10	/10	Optimal
montsthilaire-missions-F04.txt	10	7.68	7808k	10	10	10	10	/10	Optimal
montsthilaire-missions-F05.txt	10	46.63	7780k	10	10	10	10	/10	Optimal
montsthilaire-missions-F07.txt	10	59.81	7352k	1	1	1	1	/10	Echec
montsthilaire-missions-F08.txt	10	59.93	7380k	0	0	0	0	/10	Echec
montsthilaire-missions-F09.txt	10	59.88	7264k	0	0	0	0	/10	Echec
montsthilaire-missions-F10.txt	10	59.93	7524k	0	0	0	0	/10	Echec
montsthilaire-missions-F11.txt	10	59.99	7368k	0	0	0	0	/10	Echec
montsthilaire-missions-F12.txt	10	59.94	7644k	0	0	0	0	/10	Echec
montsthilaire-missions-F13.txt	10	59.97	7104k	0	0	0	0	/10	Echec
victoria-missions-D0.txt	1	0.14	31100k	1	1	1	1	/1	Optimal
victoria-missions-D1.txt	2	0.19	33736k	2	2	2	2	/2	Optimal
victoria-missions-D2.txt	10	0.35	33992k	10	10	10	10	/10	Optimal
victoria-missions-D3.txt	100	2.48	35596k	100	100	100	100	/100	Optimal
victoria-missions-D4.txt	500	12.74	36688k	500	500	500	500	/500	Optimal
victoria-missions-D5.txt	1000	23.70	37012k	1000	1000	1000	1000	/1000	Optimal
victoria-missions-D6.txt	5000	59.82	36840k	2466	2466	2466	2466	/5000	Echec
victoria-missions-F02.txt	10	0.88	35100k	10	10	10	10	/10	Optimal
victoria-missions-F03.txt	10	2.02	36092k	10	10	10	10	/10	Optimal
victoria-missions-F04.txt	10	59.61	36264k	7	7	7	7	/10	Echec
victoria-missions-F05.txt	10	59.37	36104k	1	1	1	1	/10	Echec
victoria-missions-F07.txt	10	59.89	36356k	0	0	0	0	/10	Echec
victoria-missions-F08.txt	10	59.60	34264k	1	1	1	1	/10	Echec
victoria-missions-F09.txt	10	59.65	33584k	0	0	0	0	/10	Echec
victoria-missions-F10.txt	10	59.85	36064k	0	0	0	0	/10	Echec
victoria-missions-F11.txt	10	59.67	35024k	0	0	0	0	/10	Echec
victoria-missions-F12.txt	10	59.86	35796k	0	0	0	0	/10	Echec
victoria-missions-F13.txt	10	59.36	36388k	0	0	0	0	/10	Echec
montreal-missions-D0.txt	1	0.22	43340k	1	1	1	1	/1	Optimal
montreal-missions-D1.txt	2	0.28	44388k	2	2	2	2	/2	Optimal
montreal-missions-D2.txt	10	0.69	47640k	10	10	10	10	/10	Optimal
montreal-missions-D3.txt	100	3.14	48580k	100	100	100	100	/100	Optimal
montreal-missions-D4.txt	500	18.62	52188k	500	500	500	500	/500	Optimal
montreal-missions-D5.txt	1000	39.72	53136k	1000	1000	1000	1000	/1000	Optimal
montreal-missions-D6.txt	5000	59.49	53772k	1540	1540	1540	1540	/5000	Echec
montreal-missions-F02.txt	10	1.31	50988k	10	10	10	10	/10	Optimal
montreal-missions-F03.txt	10	5.12	50960k	10	10	10	10	/10	Optimal
montreal-missions-F04.txt	10	59.78	51424k	4	4	4	4	/10	Echec
montreal-missions-F05.txt	10	59.54	51464k	0	0	0	0	/10	Echec
montreal-missions-F07.txt	10	59.21	48132k	0	0	0	0	/10	Echec
montreal-missions-F08.txt	10	59.27	48876k	0	0	0	0	/10	Echec
montreal-missions-F09.txt	10	59.86	46812k	0	0	0	0	/10	Echec
montreal-missions-F10.txt	10	59.61	49108k	0	0	0	0	/10	Echec
montreal-missions-F11.txt	10	59.24	47924k	0	0	0	0	/10	Echec
montreal-missions-F12.txt	10	59.88	48472k	0	0	0	0	/10	Echec
montreal-missions-F13.txt	10	59.90	47620k	0	0	0	0	/10	Echec



