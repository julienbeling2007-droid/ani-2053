## Exercice 12: Règles Git du projet — Groupe de 4 étudiants

### nommage des branches

main : Branche principale de production. Code stable, testé et fonctionnel uniquement.

develop : Branche d'intégration où convergent les fonctionnalités testées avant publication sur main.

Règles de nommage des branches de fonctionnalités (feature branches) :
Toute nouvelle fonctionnalité ou correction doit être développée sur sa propre branche, créée à partir de develop :

Fonctionnalité : feature/<prenom>-<description-courte> (ex. feature/loic-login-page)

Correction : bugfix/<prenom>-<description-courte> (ex. bugfix/paul-fix-header)

### contenu d'un commit 

Atomicité : Un commit = une seule modification logique ou une seule tâche. Ne mélangez pas la correction d'un bug et l'ajout d'une fonction dans le même commit.

Propreté : Ne commitez jamais de fichiers temporaires, de dépendances lourdes (node_modules/, build/, .exe) ou d'identifiants secrets (clés API, mots de passe). Vérifiez votre .gitignore.

Format des messages de commit :
Rédigez les messages au présent ou à l'impératif, clairs et concis :

feat: ajout de la validation du formulaire de contact

fix: correction du calcul du total dans le panier

docs: mise à jour du README

### Review et validation des Pull Requests (PR)
Pas de push direct sur main ou develop.

Inclusion dans develop :

Ouvrez une Pull Request (PR) de votre branche vers develop.

Chaque PR doit être relue et approuvée par au moins un membre de l'équipe (rotation libre entre les 3 autres étudiants).

L'auteur de la PR effectue la fusion (merge) après validation et supprime sa branche distante.

### Interdiction
❌ Forcer le push (git push --force ou -f) sur main ou develop.

❌ Commiter du code qui ne compile pas ou qui casse le projet.

❌ Ignorer les conflits : Ne résolvez pas un conflit en écrasant le code d'un camarade sans l'avoir consulté au préalable.

### procedure d'urgence quand main cassé
Si du code défectueux a été fusionné et bloque l'équipe :

Alerter immédiatement : Prévenez l'ensemble du groupe sur le canal de discussion du projet.

Stopper les fusions : Personne ne fusionne de nouvelle PR tant que le problème n'est pas résolu.

Annuler proprement (git revert) :

N'utilisez pas git reset --hard sur les branches partagées.

Identifiez le commit fautif et annulez-le via un commit d'annulation :
```
git revert <hash-du-commit-fautif>
git push origin develop
```

Correction à part : L'auteur du commit fautif crée une nouvelle branche bugfix/ pour corriger le problème au calme, puis repasse par le processus de PR standard.